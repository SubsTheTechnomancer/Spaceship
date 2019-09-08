#pragma once

#include "Game.hpp"
#include<string>

class Lines{
public:

    static string lines[2][8];
    static void RenderLines(SDL_Renderer* rend,SDL_Rect rect,TTF_Font* font,int cur);

};