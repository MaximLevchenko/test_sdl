#pragma once

#ifndef TEST_SDL_ENTITY_H
#define TEST_SDL_ENTITY_H

#include <SDL_image.h>
#include <SDL.h>
#include <iostream>
#include "../includes/Math.h"


using namespace std;

class Entity
{
public:
	Entity(Vector2f p_pos, SDL_Texture* p_tex );
	Vector2f & getPos(){return pos;}
	SDL_Texture * getTex();
	SDL_Rect getCurrentFrame();
private:
	Vector2f pos;
	SDL_Rect currentFrame;
	SDL_Texture * tex;


};

#endif //TEST_SDL_ENTITY_H
