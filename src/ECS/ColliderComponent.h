#pragma once
#ifndef TEST_SDL_COLLIDERCOMPONENT_H
#define TEST_SDL_COLLIDERCOMPONENT_H

#include <string>
#include "Components.h"

class ColliderComponent : public Component
{
public:
	SDL_Rect collider;
	std::string tag;//string with definition what collision have happened

	TransformComponent *transform;

	void init () override
	{
		//check if we don`t have this component already allows us to not get mistakes future on
		if (!entity->hasComponent<TransformComponent>())
		{
			entity->addComponent<TransformComponent>();
		}
		transform = &entity->getComponent<TransformComponent>();//initialization of transform
	}
	void update ()
	{
		collider.x = transform->position.x;
		collider.y = transform->position.y;
		collider.w = transform->width * transform->scale;
		collider.h = transform->height * transform->scale;
	}

private:
};

#endif //TEST_SDL_COLLIDERCOMPONENT_H
