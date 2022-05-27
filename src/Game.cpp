
#include <iostream>
#include <memory>

#include "ErrorHandler.h"
#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Vector2D.h"
#include "Collision.h"
//#include "../old_prog/gameobj_handling/GameObject.h"
using namespace std;
//we have instances of gameObjects which have all the functionality

unique_ptr<Map> map;

SDL_Renderer *Game::renderer = nullptr;

SDL_Event Game::event;


Manager manager;
auto &player(manager.addEntity());
auto &wall(manager.addEntity());

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
	map = make_unique<Map>();

	player.addComponent<TransformComponent>(2);
	player.addComponent<SpriteComponent>("../src/assets/images/player.png");
	player.addComponent<KeyboardController>();
	player.addComponent<ColliderComponent>("player");

	wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
	wall.addComponent<SpriteComponent>("../src/assets/images/dirt.png");
	wall.addComponent<ColliderComponent>("wall");
}
void Game::handleEvents ()
{
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
	manager.refresh();
	manager.update();

	if (Collision::AABB(player.getComponent<ColliderComponent>().collider,
	                    wall.getComponent<ColliderComponent>().collider))
	{
		player.getComponent<TransformComponent>().scale = 1;
		player.getComponent<TransformComponent>().velocity * -1;//bounce
		std::cout << "Wall hit" << std::endl;
	}

//	cout << cnt << endl;
}
void Game::render ()
{
	SDL_RenderClear(renderer);
	//here we add stuff to out renderer
	map->drawMap();
	manager.draw();

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



