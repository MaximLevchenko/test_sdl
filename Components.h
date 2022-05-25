#pragma once

#ifndef TEST_SDL_COMPONENTS_H
#define TEST_SDL_COMPONENTS_H

#include "ECS.h"

class PositionComponent : public Component
{
public:

	int getXpos () const {return xpos;}
	void setPpos (int p_xpos, int p_ypos)
	{
		PositionComponent::xpos = p_xpos;
		PositionComponent::ypos = p_ypos;
	}
	int getYpos () const {return ypos;}

	void init () override
	{
		xpos = 0;
		ypos = 0;
	}
	void update()
	{
		xpos++;
		ypos++;

	}
private:
	int xpos;
	int ypos;
};

#endif //TEST_SDL_COMPONENTS_H
