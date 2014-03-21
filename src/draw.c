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
 *  Role: refreshing the screen.
 */

#include "../inc/draw.h"

void draw(void)
{
    SDL_SetRenderDrawColor(home.pRendererMain, 255, 255, 255, 255);
    SDL_RenderClear(home.pRendererMain);
    SDL_RenderPresent(home.pRendererMain);

    SDL_Delay(1);
}

void delay(unsigned int frameLimit)
{
    unsigned int ticks = SDL_GetTicks();

    if (frameLimit < ticks)
    {
        return;
    }
    if (frameLimit > ticks + 16)
    {
        SDL_Delay(16);
    }
    else
    {
        SDL_Delay(frameLimit - ticks);
    }
}
