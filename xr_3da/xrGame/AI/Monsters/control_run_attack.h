#pragma once
#include "control_combase.h"

class CControlRunAttack : public CControl_ComCustom<> {
	float			m_min_dist;
	float			m_max_dist;
public:
	virtual void	load					(LPCSTR section);
	virtual void	reinit					();

	virtual void	on_event				(ControlCom::EEventType, ControlCom::IEventData*);
	virtual void	activate				();
	virtual void	on_release				();
	virtual bool	check_start_conditions	();
};

