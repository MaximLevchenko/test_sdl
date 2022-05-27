//
// Created by User win 10 on 24.05.2022.
//

#include "GameObject.h"
#include "../../src/TextureManager.h"

GameObject::~GameObject ()
{

}
GameObject::GameObject (const char *p_filename, int p_x, int p_y)
{
	objTexture = TextureManager::loadTexture(p_filename);

	xpos = p_x;
	ypos =p_y;

}
void GameObject::update_tex ()
{
	xpos++;
	ypos++;

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	dstRect.x = xpos;
	dstRect.y = ypos;
	dstRect.w = srcRect.w * 2;
	dstRect.h = srcRect.h * 2;
}
void GameObject::render_tex ()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &dstRect);

}
