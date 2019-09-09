#pragma once

#include "Game.hpp"
#include<string>

class Lines{
public:

    static string lines[2][10];
    static void RenderLines(SDL_Renderer* rend,SDL_Rect* rect,TTF_Font* font,int cur);
    static void RenderPrompt(SDL_Renderer* rend,SDL_Rect* rect,TTF_Font* font,string text);
    static void RenderInput(SDL_Renderer* rend,SDL_Rect* rect,TTF_Font* font,string input);
    static void Storyboard(int* currentScene, string Input, bool* isRunning,string* promptText);
};