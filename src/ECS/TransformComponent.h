
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
		position.x = 0.0f;
		position.y = 0.0f;

	}
	TransformComponent (float p_x, float p_y)
	{
		position.x = p_x;
		position.y = p_y;
	}

	void init () override
	{
		velocity.x = 0;
		velocity.y = 0;
	}

	void update () override
	{
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}


};

#endif //TEST_SDL_TRANSFORMCOMPONENT_H
