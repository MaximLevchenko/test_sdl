#pragma once
//
// Created by User win 10 on 19.05.2022.
//

#ifndef TEST_SDL_ERRORHANDLER_H
#define TEST_SDL_ERRORHANDLER_H
#include "iostream"
#include <SDL.h>
#include <SDL_image.h>

void logSDLError(std::ostream &os, const std::string &msg);


#endif //TEST_SDL_ERRORHANDLER_H
