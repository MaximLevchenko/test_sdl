

//
// Created by User win 10 on 24.05.2022.
//


#include <iostream>
#include <memory>

#include "ErrorHandler.h"
#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "ECS.h"
#include "Components.h"


using namespace std;
//we have instances of gameObjects which have all the functionality
unique_ptr<GameObject> grass;
unique_ptr<GameObject> player;
unique_ptr<Map> map;

SDL_Renderer *Game::renderer = nullptr;

Manager manager;
auto & newPlayer(manager.addEntity());

Game::Game () {}
Game::~Game () {}
void Game::init (const char *p_title, int p_xpos, int p_ypos, int p_w, int p_h, bool fullscreen)
{
	Uint32 flags = 0;

	if (fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		logSDLError(cout, "SDL_Init");
		isRunning = false;
	}
	if (!IMG_Init(IMG_INIT_PNG))
	{
		logSDLError(cout, "IMG_init");
		isRunning = false;
	}
	//creating window and renderer
	//==========================================================================
	window = SDL_CreateWindow(p_title, p_xpos, p_ypos, p_w, p_h, flags);
	if (window == nullptr)
	{
		logSDLError(cout, "SDL_CreateWindow");
		isRunning = false;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr)
	{
		logSDLError(cout, "SDL_CreateRenderer");
		isRunning = false;
	}
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);//setting color to white
	//==========================================================================
	isRunning = true;

	grass = make_unique<GameObject>("../assets/images/grass.png", 0, 0);
	player = make_unique<GameObject>("../assets/images/player.png", 40, 80);
	map = make_unique<Map>();

	newPlayer.addComponent<PositionComponent>();
	newPlayer.getComponent<PositionComponent>().setPpos(500,500);

}
void Game::handleEvents ()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}
}
void Game::update ()
{
	cnt++;
	grass->update_tex();
	player->update_tex();
	manager.update();
	cout<<newPlayer.getComponent<PositionComponent>().getXpos()<<",";
	cout<<newPlayer.getComponent<PositionComponent>().getYpos()<<","<<endl;

//	cout << cnt << endl;
}
void Game::render ()
{
	SDL_RenderClear(renderer);
	//here we add stuff to out renderer
	map->drawMap();
	grass->render_tex();
	player->render_tex();

	//and after this we display it
	SDL_RenderPresent(renderer);
}
void Game::clean ()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_QUIT;
	cout << "Game cleaned" << endl;
}
bool Game::running ()
{
	return isRunning;
}



