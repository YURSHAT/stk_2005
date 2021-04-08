// EffectorFall.h: interface for the CEffectorFall class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EFFECTORPP_H__06AA79FB_8954_457B_B338_039EBF4EE94E__INCLUDED_)
#define AFX_EFFECTORPP_H__06AA79FB_8954_457B_B338_039EBF4EE94E__INCLUDED_
#pragma once

#include "CameraDefs.h"
struct SPPInfo;

// постпроцесс
class ENGINE_API CEffectorPP
{
	EEffectorPPType		eType;
	bool				bFreeOnRemove;
protected:
	float				fLifeTime;
public:
						CEffectorPP		(EEffectorPPType type, f32 lifeTime, bool free_on_remove=true);
						CEffectorPP		():bFreeOnRemove(true),fLifeTime(0.0f){};
	virtual				~CEffectorPP	();
	virtual	BOOL		Process			(SPPInfo &PPInfo);
	virtual	BOOL		Valid			()							{return fLifeTime>0.0f;}
	IC EEffectorPPType	Type			()	const					{return eType;}
	IC bool				FreeOnRemove	()	const					{return bFreeOnRemove;}
	IC void				SetType			(EEffectorPPType t)			{eType=t;}
	virtual void		Stop            (float speed)				{fLifeTime=0.0f;};

};

#endif // !defined(AFX_EFFECTORPP_H__06AA79FB_8954_457B_B338_039EBF4EE94E__INCLUDED_)
