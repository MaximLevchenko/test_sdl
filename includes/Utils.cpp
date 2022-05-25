#include "Utils.h"

float hireTimeInSeconds ()
{
	float t = SDL_GetTicks();
	t *= 0.001f;
	return t;
}
