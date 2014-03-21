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
 *  main.h
 *  ------
 *
 *  By Victor Bouvier-Deleau (PlanctonFR).
 *
 *  Role:
 */

#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include "structs.h"

extern void init(char *);
extern void cleanup(void);
extern void mainLoop(void);
extern void getInput(void);
extern void draw(void);
extern void delay(unsigned int);

Input input;
Screen home;

#endif // MAIN_H_INCLUDED
