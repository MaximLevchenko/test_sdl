#pragma once
#ifndef TEST_SDL_MAP_H
#define TEST_SDL_MAP_H

#include "Game.h"

class Map
{
public:
	Map ();
	~Map ();

	void loadMap (int arr[20][25]);
	void drawMap ();
private:
	SDL_Rect src, dst;

	SDL_Texture * dirt;
	SDL_Texture * grass;
	SDL_Texture * water;

	int map[20][25];
};

#endif //TEST_SDL_MAP_H
