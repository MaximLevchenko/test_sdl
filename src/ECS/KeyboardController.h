#pragma once

#ifndef TEST_SDL_KEYBOARDCONTROLLER_H
#define TEST_SDL_KEYBOARDCONTROLLER_H

#include "../Game.h"
#include "ECS.h"
#include "Components.h"

class KeyboardController : public Component
{

public:
	TransformComponent *transform;

	void init () override
	{
		transform = &entity->getComponent<TransformComponent>();//initialization of transform
	}

	void update () override
	{
		if (Game::event.type == SDL_KEYDOWN)
		{
			switch (Game::event.key.keysym.sym)
			{
				case SDLK_w:
					transform->velocity.y = -1;//it will move the player up because of pos.y = velocity.y * speed
					break;
				case SDLK_a:
					transform->velocity.x = -1;
					break;
				case SDLK_d:
					transform->velocity.x = 1;
					break;
				case SDLK_s:
					transform->velocity.y = 1;
					break;
				default:
					break;
			}
		}
		if (Game::event.type == SDL_KEYUP)//when we release the key, we set our velocity to 0
		{
			switch (Game::event.key.keysym.sym)
			{
				case SDLK_w:
					transform->velocity.y = 0;
					break;
				case SDLK_a:
					transform->velocity.x = 0;
					break;
				case SDLK_d:
					transform->velocity.x = 0;
					break;
				case SDLK_s:
					transform->velocity.y = 0;
					break;
				default:
					break;
			}
		}
	}

};

#endif //TEST_SDL_KEYBOARDCONTROLLER_H
