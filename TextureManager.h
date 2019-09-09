#pragma once

#include "Game.hpp"

class TextureManager{
    
public:
    static SDL_Texture* LoadTexture(int currentScene,SDL_Renderer* rend);
    static SDL_Texture* LoadTTF(const char* fontfile,TTF_Font* font,SDL_Renderer* rend,string Text);
    static SDL_Rect ImageRect();
};
