#pragma once
#ifndef TEST_SDL_GAMEOBJECT_H
#define TEST_SDL_GAMEOBJECT_H

#include "Game.h"
class GameObject
{
public:
	~GameObject ();
	GameObject (const char * p_filename, int p_x, int p_y);

	void update_tex();
	void render_tex();

private:
	int ypos;
	int xpos;

	SDL_Texture * objTexture;
	SDL_Rect srcRect,dstRect;
};

#endif //TEST_SDL_GAMEOBJECT_H
