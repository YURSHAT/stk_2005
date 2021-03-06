#include "stdafx.h"
#pragma hdrstop

#include "Blender_Blur.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBlender_Blur::CBlender_Blur()
{
	description.CLS		= B_BLUR;
}

CBlender_Blur::~CBlender_Blur()
{

}

void	CBlender_Blur::Save	( CFS_Base& FS	)
{
	CBlender::Save	(FS);
}

void	CBlender_Blur::Load	( CStream& FS, WORD version	)
{
	CBlender::Load	(FS,version);
}

void CBlender_Blur::Compile	(CBlender_Compile& C)
{
	CBlender::Compile		(C);
	C.PassBegin		();
	{
		C.PassSET_ZB		(FALSE, FALSE);
		C.PassSET_Blend_SET	();
		C.PassSET_LightFog	(FALSE, FALSE);

		// Stage0 - B0*F
		C.StageBegin		();
		C.StageSET_Color	(D3DTA_TEXTURE,	  D3DTOP_MODULATE,		D3DTA_TFACTOR);
		C.StageSET_Alpha	(D3DTA_TEXTURE,	  D3DTOP_SELECTARG1,	D3DTA_TFACTOR);
		C.Stage_Texture		("$base0");
		C.Stage_Matrix		("$null",0);
		C.Stage_Constant	("$null");
		C.StageEnd			();

		// Stage1 - B1*F + current
		C.StageBegin		();
		C.StageSET_Color3	(D3DTA_TEXTURE,	  D3DTOP_MULTIPLYADD,	D3DTA_TFACTOR, D3DTA_CURRENT);
		C.StageSET_Alpha	(D3DTA_CURRENT,	  D3DTOP_SELECTARG1,	D3DTA_TFACTOR);
		C.Stage_Texture		("$base1");
		C.Stage_Matrix		("$null",0);
		C.Stage_Constant	("$null");
		C.StageEnd			();
		
		// 
		C.R().SetRS			(D3DRS_TEXTUREFACTOR,D3DCOLOR_RGBA(127,127,127,127));
	}
	C.PassEnd			();
}
