#pragma once

#include <SDL.h>
#include "SDL_image.h"
#include <iostream>

#ifndef TEST_SDL_MATH_H
#define TEST_SDL_MATH_H

using namespace std;

class Vector2f
{
public:
	Vector2f () : x(0.0f), y(0.0f) {}
	Vector2f (float p_x, float p_y) : x(p_x), y(p_y) {}

	void print ()
	{
		cout << getX() << ", " << getY() << endl;
	}
	float getX () const {return x;}
	float getY () const {return y;}
private:
	float x, y;
};

#endif //TEST_SDL_MATH_H
