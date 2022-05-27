
#pragma once

#ifndef TEST_SDL_TRANSFORMCOMPONENT_H
#define TEST_SDL_TRANSFORMCOMPONENT_H

#include "Components.h"
#include "../Vector2D.h"

class TransformComponent : public Component
{
public:
	Vector2D position;
	Vector2D velocity;

	int speed = 3;
	int height = 32;
	int width = 32;
	int scale = 1;

	TransformComponent ()
	{
		position.zero();//initialize x and y to zero

	}
	TransformComponent(int p_scale)
	{
		position.zero();
		scale = p_scale;
	}
	TransformComponent (float p_x, float p_y)
	{
		position.zero();
//		position.x = p_x;
//		position.y = p_y;
	}

	TransformComponent (float p_x, float p_y, int p_h, int p_w, int p_scale)
	{
		position.x = p_x;
		position.y = p_y;
		height = p_h;
		width = p_w;
		scale = p_scale;
	}

	void init () override
	{
		velocity.zero();
	}

	void update () override
	{
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}


};

#endif //TEST_SDL_TRANSFORMCOMPONENT_H
