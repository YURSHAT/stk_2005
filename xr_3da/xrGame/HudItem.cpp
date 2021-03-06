//////////////////////////////////////////////////////////////////////
// HudItem.cpp: ????? ???????? ??? ???? ????????? ???????
//				??????????? HUD (CWeapon, CMissile etc)
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HudItem.h"
#include "physic_item.h"
#include "WeaponHUD.h"
#include "actor.h"
#include "actoreffector.h"
#include "Missile.h"
#include "xrmessages.h"
#include "level.h"
#include "inventory.h"
#include "../CameraBase.h"

//////////////////////////////////////////////////////////////////////////

//??? ??????? HUD
//????????? ????????
static float			m_fInertYawMin;
static float			m_fInertYawMax;
static float			m_fInertPitchMin;
static float			m_fInertPitchMax;
//???????? ??????????????
static float			m_fInertYawRestoreSpeed;
static float			m_fInertPitchRestoreSpeed;



//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

CHudItem::CHudItem(void)
{
	m_pHUD				= NULL;
	hud_mode			= FALSE;
	m_dwStateTime		= 0;
	m_bRenderHud		= true;

	m_bInertionEnable	= true;
	m_bInertionAllow	= true;
}

CHudItem::~CHudItem(void)
{
	xr_delete			(m_pHUD);
}

DLL_Pure *CHudItem::_construct	()
{
	m_object			= smart_cast<CPhysicItem*>(this);
	VERIFY				(m_object);

	m_item				= smart_cast<CInventoryItem*>(this);
	VERIFY				(m_item);

	return				(m_object);
}

void CHudItem::Load(LPCSTR section)
{
	//????????? hud, ???? ?? ?????
	if(pSettings->line_exist(section,"hud"))
		hud_sect		= pSettings->r_string		(section,"hud");

	if(*hud_sect){
		m_pHUD			= xr_new<CWeaponHUD> (this);
		m_pHUD->Load	(*hud_sect);
		if(pSettings->line_exist(*hud_sect, "allow_inertion")) 
			m_bInertionAllow = !!pSettings->r_bool(*hud_sect, "allow_inertion");
	}else{
		m_pHUD = NULL;
		//???? hud ?? ?????, ?? ????? ????, ?? ??????
		R_ASSERT2(item().GetSlot() == NO_ACTIVE_SLOT, "active slot is set, but hud for food item is not available");
	}

	m_animation_slot	= pSettings->r_u32(section,"animation_slot");
}

void CHudItem::net_Destroy()
{
	if(m_pHUD)
		m_pHUD->net_DestroyHud	();

	hud_mode			= FALSE;
	m_dwStateTime		= 0;
}

void CHudItem::PlaySound	(HUD_SOUND& hud_snd, const Fvector& position)
{
	HUD_SOUND::PlaySound	(hud_snd, position, object().H_Root(), !!hud_mode);
}

BOOL  CHudItem::net_Spawn	(CSE_Abstract* DC) 
{
	return TRUE;
}

void CHudItem::renderable_Render()
{
	UpdateXForm	();
	BOOL _hud_render			= ::Render->get_HUD() && hud_mode;
	if(_hud_render && !m_pHUD->IsHidden() && !item().IsHidden()){ 
		// HUD render
		if(m_bRenderHud){
			::Render->set_Transform		(&m_pHUD->Transform());
			::Render->add_Visual		(m_pHUD->Visual());
		}
	}else if(!object().H_Parent() || (!_hud_render && m_pHUD && !m_pHUD->IsHidden() && !item().IsHidden())){
		on_renderable_Render	();
	}
}

bool CHudItem::Action(s32 cmd, u32 flags) 
{
	return false;
}

void CHudItem::OnAnimationEnd()
{
}

void CHudItem::SwitchState(u32 S)
{
	NEXT_STATE		= S;	// Very-very important line of code!!! :)

	if (object().Local() && !object().getDestroy())	
	{
		// !!! Just single entry for given state !!!
		NET_Packet		P;
		object().u_EventGen		(P,GE_WPN_STATE_CHANGE,object().ID());
		P.w_u8			(u8(S));
		object().u_EventSend		(P);
	}
}

void CHudItem::OnEvent		(NET_Packet& P, u16 type)
{
	switch (type)
	{
	case GE_WPN_STATE_CHANGE:
		{
			u8				S;
			P.r_u8			(S);
			OnStateSwitch	(u32(S));
		}
		break;
	}
}

void CHudItem::OnStateSwitch	(u32 S)
{
	m_dwStateTime = 0;
	STATE = S;
	if(object().Remote()) NEXT_STATE = S;
}


bool CHudItem::Activate() 
{
	if(m_pHUD) 
		m_pHUD->Init();

	Show();
	return true;
}

void CHudItem::Deactivate() 
{
	Hide();
}



void CHudItem::UpdateHudPosition	()
{
	if (m_pHUD && hud_mode){
		if(item().IsHidden()) hud_mode = false;

		Fmatrix							trans;

		CActor* pActor = smart_cast<CActor*>(object().H_Parent());
		if(pActor){
			pActor->EffectorManager().affected_Matrix	(trans);
			UpdateHudInertion							(trans, pActor->cam_FirstEye()->yaw, pActor->cam_FirstEye()->pitch);
			UpdateHudAdditonal							(trans);
			m_pHUD->UpdatePosition						(trans);
		}
	}
}

void CHudItem::UpdateHudAdditonal		(Fmatrix& hud_trans)
{
}

void CHudItem::StartHudInertion()
{
	m_bInertionEnable = true;
}
void CHudItem::StopHudInertion()
{
	m_bInertionEnable = false;
}

static const float PITCH_OFFSET_R	= 0.017f;
static const float PITCH_OFFSET_N	= 0.012f;
static const float PITCH_OFFSET_D	= 0.02f;
static const float ORIGIN_OFFSET	= -0.05f;
static const float TENDTO_SPEED		= 5.f;

void CHudItem::UpdateHudInertion		(Fmatrix& hud_trans, float actor_yaw, float actor_pitch)
{
	if (m_pHUD && m_bInertionAllow && m_bInertionEnable){
		Fmatrix			xform,xform_orig; 
		Fvector& origin	= hud_trans.c; 
		Level().Cameras().affected_Matrix		(xform);
		Level().Cameras().unaffected_Matrix	(xform_orig);

		static Fvector						m_last_dir={0,0,0};

		// calc difference
		Fvector								diff_dir;
		diff_dir.sub						(xform.k, m_last_dir);

		// clamp by PI_DIV_2
		Fvector last;						last.normalize_safe(m_last_dir);
		float dot							= last.dotproduct(xform.k);
		if (dot<EPS){
			Fvector v0;
			v0.crossproduct			(m_last_dir,xform.k);
			m_last_dir.crossproduct	(xform.k,v0);
			diff_dir.sub			(xform.k, m_last_dir);
		}

		// tend to forward
		m_last_dir.mad	(diff_dir,TENDTO_SPEED*Device.fTimeDelta);
		origin.mad		(diff_dir,ORIGIN_OFFSET);

		// pitch compensation
		float pitch		= angle_normalize_signed(xform_orig.k.getP());
		origin.mad		(xform_orig.k,	-pitch * PITCH_OFFSET_D);
		origin.mad		(xform_orig.i,	-pitch * PITCH_OFFSET_R);
		origin.mad		(xform_orig.j,	-pitch * PITCH_OFFSET_N);

		// calc moving inertion
	}
}

void CHudItem::UpdateCL()
{
	m_dwStateTime += Device.dwTimeDelta;

	if(m_pHUD) m_pHUD->Update();
	UpdateHudPosition	();
}

void CHudItem::OnH_A_Chield		()
{
	hud_mode = FALSE;
	
	if (m_pHUD) {
		if(Level().CurrentEntity() == object().H_Parent() && smart_cast<CActor*>(object().H_Parent()))
			m_pHUD->Visible(true);
		else
			m_pHUD->Visible(false);
	}
}

void CHudItem::OnH_B_Chield		()
{
	if (item().m_pInventory && item().m_pInventory->ActiveItem() == smart_cast<PIItem>(this))
		OnActiveItem ();
	else
		OnHiddenItem ();
}

void CHudItem::OnH_B_Independent	()
{
	hud_mode = FALSE;
	if (m_pHUD)
		m_pHUD->Visible(false);
	
	StopHUDSounds();
	UpdateXForm();
}

void CHudItem::OnH_A_Independent	()
{
}
