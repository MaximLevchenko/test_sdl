#pragma once

#ifndef TEST_SDL_COLLISION_H
#define TEST_SDL_COLLISION_H

#include "SDL.h"

class Collision
{
public:
	static bool AABB(const SDL_Rect & recA,const SDL_Rect & recB );//access aligned bounding box

};

#endif //TEST_SDL_COLLISION_H
