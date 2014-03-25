/**
 *  This file is part of GUI-Lux3.
 *
 *  GUI-Lux3 is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  any later version.
 *
 *  GUI-Lux3 is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with GUI-Lux3.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 *  prog.c
 *  ------
 *
 *  By Victor Bouvier-Deleau (PlanctonFR).
 *
 *  Role: main program.
 */

#include "../inc/prog.h"

void mainLoop(void)
{
    int quit = 0;
    int frameLimit = SDL_GetTicks() + 16;

    Texture button = loadTexture("res/img/button/button.png");

    while(!quit)
    {
        quit = getInput();

        buttonQuit.srcRect.w = button.w;
        buttonQuit.srcRect.h = button.h;
        buttonQuit.srcRect.x = 0;
        buttonQuit.srcRect.y = 0;
        buttonQuit.dstRect.w = buttonQuit.srcRect.w;
        buttonQuit.dstRect.h = buttonQuit.srcRect.h;
        buttonQuit.dstRect.x = (WINDOW_WIDTH / 2) - (buttonQuit.dstRect.w / 2);
        buttonQuit.dstRect.y = (WINDOW_HEIGHT / 2) - (buttonQuit.dstRect.h / 2);

        buttonAccept.srcRect.w = button.w;
        buttonAccept.srcRect.h = button.h;
        buttonAccept.srcRect.x = 0;
        buttonAccept.srcRect.y = 0;
        buttonAccept.dstRect.w = buttonAccept.srcRect.w;
        buttonAccept.dstRect.h = buttonAccept.srcRect.h;
        buttonAccept.dstRect.x = 0;
        buttonAccept.dstRect.y = 0;

        draw();

        blitTexture(button, buttonQuit);
        blitTexture(button, buttonAccept);

        delay(frameLimit);
        frameLimit = SDL_GetTicks() + 16;
    }

    SDL_DestroyTexture(button.texture);

    exit(0);
}

Texture loadTexture(char *path)
{
    Texture newTexture;

    newTexture.texture = NULL;
    newTexture.h = 0;
    newTexture.w = 0;

    SDL_Surface* loadedSurface = IMG_Load(path);
    if(loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n",
               path,
               IMG_GetError());
    }
    else
    {
        newTexture.texture = SDL_CreateTextureFromSurface(home.pRendererMain,
                                                  loadedSurface);
        if(newTexture.texture == NULL)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n",
                   path,
                   SDL_GetError());
        }
        newTexture.h = loadedSurface->h;
        newTexture.w = loadedSurface->w;

        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
}

void blitTexture(Texture texture, Sprite sprite)
{
    SDL_RenderCopy(home.pRendererMain, texture.texture, &sprite.srcRect, &sprite.dstRect);
}
