#ifndef PROG_H_INCLUDED
#define PROG_H_INCLUDED

#include "main.h"

void mainLoop(void);
Texture loadTexture(char *path);
void blitTexture(Texture texture, Sprite sprite);

Sprite buttonQuit, buttonAccept;
Texture button;

#endif // PROG_H_INCLUDED
