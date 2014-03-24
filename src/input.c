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
 *  main.c
 *  ------
 *
 *  By Victor Bouvier-Deleau (PlanctonFR).
 *
 *  Role: Getting the user inputs.
 */

#include "../inc/input.h"

int getInput(void)
{
    int quit = 0;
    SDL_Event event;

    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
        case SDL_QUIT:
            quit = 1;
            break;

        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                quit = 1;
                break;

            case SDLK_DELETE:
                input.erase = 1;
                break;

            case SDLK_LEFT:
                input.left = 1;
                break;

            case SDLK_RIGHT:
                input.right = 1;
                break;

            case SDLK_DOWN:
                input.down = 1;
                break;

            case SDLK_UP:
                input.up = 1;
                break;

            case SDLK_RETURN:
                input.enter = 1;
                break;

            default:
                break;
            }
            break;

        case SDL_KEYUP:
            switch(event.key.keysym.sym)
            {
            case SDLK_DELETE:
                input.erase = 0;
                break;

            case SDLK_LEFT:
                input.left = 0;
                break;

            case SDLK_RIGHT:
                input.right = 0;
                break;

            case SDLK_DOWN:
                input.down = 0;
                break;

            case SDLK_UP:
                input.up = 0;
                break;

            case SDLK_RETURN:
                input.enter = 0;
                break;

            default:
                break;
            }
            break;

        default:
            break;
        }
    }
    return quit;
}
