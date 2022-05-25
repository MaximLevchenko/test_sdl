#include "Entity.h"

Entity::Entity (Vector2f p_pos, SDL_Texture *p_tex)
		: pos(p_pos), tex(p_tex)
{
	currentFrame.x = 0; //x,y,w,h all declared in SDL
	currentFrame.y = 0;
	currentFrame.w = 32;
	currentFrame.h = 32;
}

SDL_Texture *Entity::getTex ()
{
	return tex;
}
SDL_Rect Entity::getCurrentFrame ()
{
	return currentFrame;
}
