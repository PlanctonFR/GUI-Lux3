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

    while(!quit)
    {
        getInput();

        SDL_Texture* button = loadTexture("res/img/button/button.png");

        draw();

        delay(frameLimit);
        frameLimit = SDL_GetTicks() + 16;
    }
}

SDL_Texture* loadTexture(char *path)
{
    SDL_Texture* newTexture = NULL;

    SDL_Surface* loadedSurface = IMG_Load(path);
    if(loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n",
               path,
               IMG_GetError());
    }
    else
    {
        newTexture = SDL_CreateTextureFromSurface(home.pRendererMain,
                                                  loadedSurface);
        if(newTexture == NULL)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n",
                   path,
                   SDL_GetError());
        }

        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
}
