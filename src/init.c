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
 *  init.c
 *  ------
 *
 *  By Victor Bouvier-Deleau (PlanctonFR).
 *
 *  Role: initializing and closing the SDL.
 */

#include "../inc/init.h"

void init(char *pTitle)
{
    /* Initialize the libraries */

    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stderr,
                "Couldn't initialize SDL: %s\n",
                SDL_GetError());
        exit(EXIT_FAILURE);
    }

    if(TTF_Init() != 0)
    {
        fprintf(stderr,
                "Couldn't initialize TTF: %s\n",
                TTF_GetError());
        exit(EXIT_FAILURE);
    }

    /* Create the window */

    home.pWindowMain = SDL_CreateWindow(pTitle,
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          WINDOW_WIDTH,
                                          WINDOW_HEIGHT,
                                          SDL_WINDOW_SHOWN);

    home.pRendererMain = SDL_CreateRenderer(home.pWindowMain,
                           -1,
                           SDL_RENDERER_ACCELERATED |
                           SDL_RENDERER_PRESENTVSYNC);

    if(home.pWindowMain == NULL || home.pRendererMain == NULL)
    {
        fprintf(stderr,
                "Couldn't create a %d x %d window: %s\n",
                WINDOW_WIDTH, WINDOW_HEIGHT, SDL_GetError());
        exit(EXIT_FAILURE);
    }

    /* Set the window icon */

    SDL_SetWindowIcon(home.pWindowMain,
                      IMG_Load("res/icon/icon.png"));

    /* Initialising the Window */

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,
                "linear");
    SDL_RenderSetLogicalSize(home.pRendererMain,
                             WINDOW_WIDTH,
                             WINDOW_HEIGHT);

    SDL_SetRenderDrawColor(home.pRendererMain,
                           0,
                           0,
                           0,
                           255);
    SDL_RenderClear(home.pRendererMain);
    SDL_RenderPresent(home.pRendererMain);
}

void cleanup(void)
{
    /* Close the devices */

    //TTF_CloseFont(font.pFontText);
    //TTF_CloseFont(font.pFontTitle);

    SDL_DestroyTexture(button.texture);

    SDL_DestroyRenderer(home.pRendererMain);
    SDL_DestroyWindow(home.pWindowMain);

    TTF_Quit();
    SDL_Quit();
}
