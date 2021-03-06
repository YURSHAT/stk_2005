#pragma once

#include "../../actor_input_handler.h"

class CControlledActor : public CActorInputHandler {
	typedef CActorInputHandler inherited;
	
	Fvector m_target_point;
	
	bool	m_turned_yaw;
	bool	m_turned_pitch;

public:
	virtual void	reinit				();
	virtual	float	mouse_scale_factor	(){return flt_max;}
	virtual void	release				();
	virtual bool	authorized			(int cmd);

			void	look_point			(const Fvector &point);
			bool	is_turning			();

			void	frame_update		();
			bool	is_controlling		() {return m_actor != 0;}

private:
			void	reset				();
			void	update_turn			();
};	

