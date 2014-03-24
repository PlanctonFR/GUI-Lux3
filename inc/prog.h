#ifndef PROG_H_INCLUDED
#define PROG_H_INCLUDED

#include "main.h"

void mainLoop(void);
SDL_Texture* loadTexture(char *path);
void blitTexture(Sprite sprite);

Sprite button;

#endif // PROG_H_INCLUDED
