// Effector.h: interface for the CEffector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EFFECTOR_H__E8300C00_1C3E_11D4_B4E3_00C02610C34E__INCLUDED_)
#define AFX_EFFECTOR_H__E8300C00_1C3E_11D4_B4E3_00C02610C34E__INCLUDED_

#pragma once

#include "CameraDefs.h"
//#include "../script_export_space.h"

class CCameraShotEffector;
class CEffectorZoomInertion;

class ENGINE_API		CEffectorCam
{
protected:
	ECamEffectorType	eType;
	
	friend class		CCameraManager;
	float				fLifeTime;
public:
						CEffectorCam	(ECamEffectorType type, float tm)	{eType=type; fLifeTime=tm;};
						CEffectorCam	()									{eType=(ECamEffectorType)0; fLifeTime=0.0f;};
	virtual				~CEffectorCam	()									{};
			void		SetType			(ECamEffectorType type)				{eType=type;}
	IC ECamEffectorType	GetType			()									{return eType;}
	virtual	BOOL		Valid			()									{return fLifeTime>0.0f;}
	IC virtual BOOL		Overlapped		()									{return FALSE;}

	virtual	BOOL		Process			(Fvector &p, Fvector &d, Fvector &n, float& fFov, float& fFar, float& fAspect){fLifeTime-=Device.fTimeDelta; return Valid();};

	virtual CCameraShotEffector		*cast_effector_shot()	{ return 0; }
	virtual CEffectorZoomInertion	*cast_effector_zoom_inertion()	{ return 0; }

//public:
//	DECLARE_SCRIPT_REGISTER_FUNCTION
};

//add_to_type_list(CEffectorCam)
//#undef script_type_list
//#define script_type_list save_type_list(CEffectorCam)


#endif // !defined(AFX_EFFECTOR_H__E8300C00_1C3E_11D4_B4E3_00C02610C34E__INCLUDED_)
