#pragma once
//
// Created by User win 10 on 24.05.2022.
//

#ifndef TEST_SDL_TEXTUREMANAGER_H
#define TEST_SDL_TEXTUREMANAGER_H

#include <iostream>

#include "ErrorHandler.h"
using namespace std;

#include "Game.h"

class TextureManager{
public:
	static SDL_Texture * loadTexture(const char * p_filename);
	static void draw(SDL_Texture * tex, SDL_Rect src, SDL_Rect dst );

};

#endif //TEST_SDL_TEXTUREMANAGER_H
