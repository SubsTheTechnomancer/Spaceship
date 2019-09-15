#ifndef Game_hpp
#define Game_hpp

#include<iostream>
#include<fstream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_Image.h>
#include<SDL2/SDL_ttf.h>
#include<SDL2/SDL_net.h>
#include<string>

using namespace std;

class Game{
public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();

    bool running(){
        return isRunning;
    }

private:

    bool isRunning;
    int currentScene;
    int situation;
    string name;
    string promptText;
    string Input;
    SDL_Window *window;
    SDL_Window *tWindow;
    SDL_Renderer *renderer;
    SDL_Renderer *trenderer;

};

#endif