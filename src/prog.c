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
    int frameLimit = SDL_GetTicks() + 16;
    int quit = 0;

    while (!quit)
    {
        getInput();

        draw();

        delay(frameLimit);
        frameLimit = SDL_GetTicks() + 16;
    }
}
