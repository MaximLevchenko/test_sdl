#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include <memory>

//#include "RenderWindow.h"
//#include "Entity.h"
//#include "includes/Utils.h"
//#include "includes/ErrorHandler.h"

#include "Game.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

using namespace std;

unique_ptr<Game> game = make_unique<Game>();

int main (int argc, char *args[])
{
	const int FPS =60;
	const int frameDelay = 1000/FPS;

	Uint32 frameStart;
	int frameTime;

	game->init("Game v1.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
	while (game->running())
	{
		frameStart = SDL_GetTicks(); //ticks since we first initialized sdl
		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;//how long it took to go through 1 cycle of main loop

		if(frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
	game->clean();
	std::cout << "Hello, World!" << std::endl;

//	make_unique<Game>(game);
//initializing everything
//=============================================================================================================
//	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
//	{
//		logSDLError(cout, "SDL_Init");
//	}
//
//	if (!IMG_Init(IMG_INIT_PNG))
//	{
//		logSDLError(cout, "IMG_init");
//	}
//=============================================================================================================

//creating a new window and creating a renderer
//	RenderWindow window("Game v1.0", SCREEN_WIDTH, SCREEN_HEIGHT);

//	cout << window.getRefreshRate() << endl;
//
//	//loading grass texture
//	//=============================================================================================================
//	SDL_Texture *grassTexture = window.loadTexture("../res/images/grass.png");
//	vector<Entity> entities = {Entity(Vector2f(0, 0), grassTexture),
//	                           Entity(Vector2f(30, 0), grassTexture),
//	                           Entity(Vector2f(0, 30), grassTexture)};
//	//=============================================================================================================
//	entities.emplace_back(Vector2f(30, 60), grassTexture);
//	bool gameRunning = true;
//
//	SDL_Event event;
//
//	const float timeStep = 0.01f;
//	float accumulator = 0.0f;
//	float currentTime = hireTimeInSeconds();
//	while (game->running())
//	{
//		int startTicks = SDL_GetTicks();
//		float newTime = hireTimeInSeconds();
//		float frameTime = newTime - currentTime;
//
//		currentTime = newTime;
//		accumulator += frameTime;
//		while (accumulator >= timeStep)
//		{
//			while (SDL_PollEvent(&event))
//			{
//				if (event.type == SDL_QUIT)
//					gameRunning = false;
//			}
//			accumulator -= timeStep;
//		}
//
//		const float alpha = accumulator / timeStep;
//		//clears the whole renderer
//		window.clear();
//		//for loop to render the object
//		for (auto &entity: entities)
//		{
//			window.render(entity);
//		}
//
//		cout << hireTimeInSeconds() << endl;
//
//		window.display();
//		int frameTicks = SDL_GetTicks() - startTicks;
//		if (frameTicks < 1000/window.getRefreshRate())
//			SDL_Delay(1000/window.getRefreshRate()-frameTicks);
//	}
//	window.cleanUp();
//	SDL_Quit();
//
//	std::cout << "Hello, World!" << std::endl;
	return 0;
}
