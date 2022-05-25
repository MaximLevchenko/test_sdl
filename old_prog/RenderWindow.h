#pragma once




#ifndef TEST_SDL_RENDERWINDOW_H
#define TEST_SDL_RENDERWINDOW_H
#include "Entity.h"
#include <SDL.h>
#include "SDL_image.h"
class RenderWindow
{
public:
	RenderWindow (const char *p_title, int p_w, int p_h);
	SDL_Texture *loadTexture(const char * p_filePath);

	int getRefreshRate();

	void cleanUp ();
	void clear();
	void render(Entity & p_entity);
	void display();
private:
	SDL_Window *window;
	SDL_Renderer *renderer;
};
#endif //TEST_SDL_RENDERWINDOW_H
