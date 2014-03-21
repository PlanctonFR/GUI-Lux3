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
 *  Role: initializing the SDL, and launching the program menu.
 */

#include "../inc/main.h"

int main(int argc, char** argv)
{
    /* INITIALIZATIONS ===================================================== */

    init("GUI-Lux3");

    atexit(cleanup);

    /* LAUNCH THE PROGRAM ================================================== */

    mainLoop();

    /* QUIT THE PROGRAMM =================================================== */

    return EXIT_SUCCESS;
}
