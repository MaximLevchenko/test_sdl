#pragma once
#ifndef TEST_SDL_SPRITECOMPONENT_H
#define TEST_SDL_SPRITECOMPONENT_H

#include "Components.h"
#include "SDL.h"
#include "SDL_image.h"
#include "../TextureManager.h"

class SpriteComponent: public Component{
public:

	SpriteComponent() =default;
	SpriteComponent(const char * p_filename)
	{
		setTex(p_filename);
	}
~SpriteComponent()
{
	SDL_DestroyTexture(texture);
}

	//if any further we wan
	void setTex(const char* p_filename)
	{
		texture = TextureManager::loadTexture(p_filename);
	}

	void init()override
	{
		transform = &entity->getComponent<TransformComponent>();//initializes position

		srcRect.x = srcRect.y = 0;
		srcRect.w = transform->width;
		srcRect.h = transform->height;


	}
	void update()override
	{
		destRect.x = (int)transform->position.x;
		destRect.y = (int)transform->position.y;
		destRect.w = transform->width * transform->scale;
		destRect.h = transform->height * transform->scale;

	}
	void draw()override
	{
		TextureManager::draw(texture,srcRect,destRect);
	}

private:
	TransformComponent * transform;
	SDL_Texture * texture;
	SDL_Rect srcRect, destRect;

};

#endif //TEST_SDL_SPRITECOMPONENT_H
