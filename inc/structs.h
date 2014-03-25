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
 *  Role: defining global structures.
 */

#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#include "defs.h"

typedef struct Screen
{
    SDL_Window *pWindowMain;
    SDL_Renderer *pRendererMain;
}Screen;

typedef struct Font
{
    TTF_Font *pFontTitle;
    TTF_Font *pFontText;
}Font;

typedef struct Input
{
    int left, right, up, down, exit, enter, erase;
}Input;

typedef struct Texture
{
    SDL_Texture* texture;
    int w, h;
}Texture;

typedef struct Sprite
{
    SDL_Rect srcRect, dstRect;
}Sprite;

#endif // STRUCTS_H_INCLUDED
