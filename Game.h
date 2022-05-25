//
// Created by User win 10 on 24.05.2022.
//
#include "SDL.h"
#include "SDL_image.h"
#ifndef TEST_SDL_GAME_H
#define TEST_SDL_GAME_H

class Game
{
public:
	~Game ();
	Game ();
	void init(const char *p_title,int p_xpos, int p_ypos, int p_w, int p_h, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running();
	static SDL_Renderer * renderer;
private:
	int cnt = 0;
	bool isRunning;
	SDL_Window * window;

};

#endif //TEST_SDL_GAME_H
