#pragma once

#include "Game.hpp"
#include<string>

class Lines{
public:

    static int time;
    static int location;
    static string lines[9][10];
    static void RenderLines(SDL_Renderer* rend,SDL_Rect* rect,TTF_Font* font,int cur);
    static void RenderPrompt(SDL_Renderer* rend,SDL_Rect* rect,TTF_Font* font,string text);
    static void RenderInput(SDL_Renderer* rend,SDL_Rect* rect,TTF_Font* font,string input);
    static void Storyboard(int* currentScene, int situation, string name, string Input, bool* isRunning,string* promptText);
};