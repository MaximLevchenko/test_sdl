#include <iostream>
#include "../includes/Utils.h"
#include "../ErrorHandler.h"
#include "RenderWindow.h"

using namespace std;



RenderWindow::RenderWindow (const char *p_title, int p_w, int p_h) : window(nullptr), renderer(nullptr)
{
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
	if (window == nullptr)
		logSDLError(cout, "SDL_CreateWindow");

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr)
	{
		logSDLError(cout, "SDL_CreateRenderer");

	}
}

SDL_Texture *RenderWindow::loadTexture (const char *p_filePath)
{

	SDL_Texture *texture = nullptr;//initializing a new texture;
	texture = IMG_LoadTexture(renderer, p_filePath);//load a texture from a file

	if (texture == nullptr)
		logSDLError(cout, "IMG_LoadTexture");

	return texture;
}

void RenderWindow::cleanUp ()
{
	SDL_DestroyWindow(window);
}

void RenderWindow::clear ()
{
	SDL_RenderClear(renderer);
}

void RenderWindow::render (Entity &p_entity)
{
	SDL_Rect src;
	src.x = p_entity.getCurrentFrame().x;
	src.y = p_entity.getCurrentFrame().y;
	src.w = p_entity.getCurrentFrame().w;;
	src.h = p_entity.getCurrentFrame().h;;
	//^ we can not do this part of the code if we just use SDL_QueryTexture, which gets height and width of the texture we are passing

	SDL_Rect dst;
	dst.x = p_entity.getPos().getX() * 4;
	dst.y = p_entity.getPos().getY() * 4;
	dst.w = p_entity.getCurrentFrame().w * 4;
	dst.h = p_entity.getCurrentFrame().h * 4;

	SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dst);
}

void RenderWindow::display ()
{
	SDL_RenderPresent(renderer);
}

int RenderWindow::getRefreshRate ()
{
	int displayIndex = SDL_GetWindowDisplayIndex(window);
	SDL_DisplayMode mode;
	SDL_GetDisplayMode(displayIndex, 0, &mode);
	return mode.refresh_rate;
}

