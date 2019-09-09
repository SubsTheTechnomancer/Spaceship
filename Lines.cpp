#include "Lines.h"

//Number of Letters per line: 53

string Lines::lines[2][10] = {{"                     SPACESHIP                 ",
                              "                                               ",
                              "                                               ",
                              "     Welcome to SPACESHIP! Can you survive?    ",
                              "                                               ",
                              "         Type Play to start the game           ",
                              "                                               ",
                              "          Type Exit to exit the game           ",
                              "                       adadwa                  "},
                             {"                     SPACESHIP                 ",
                              "is displaying something in the text window so  ",
                              "So that I can write a script              "}};

void Lines::RenderLines(SDL_Renderer* rend,SDL_Rect* rect,TTF_Font *font,int cur){

    int w = 0,h = 0;

    for(int i = 0; !lines[cur][i].empty() ; i++){

        SDL_Texture *tex = TextureManager::LoadTTF("TTF/alienleague.ttf",font,rend,lines[cur][i]);
        SDL_QueryTexture(tex,NULL,NULL,&w,&h);
        *rect = {rect->x,rect->y,w,h};
        SDL_RenderCopy(rend,tex,NULL,rect);
        SDL_DestroyTexture(tex);

        rect->y +=(35);

    }

    rect->y = 0;

}

void Lines::RenderInput(SDL_Renderer* rend,SDL_Rect* rect,TTF_Font* font,string input){
    int w,h;
    rect->x = 0;
    rect->y = 500;
    SDL_Texture *tex = TextureManager::LoadTTF("TTF/alienleague.ttf",font,rend,input);
    SDL_QueryTexture(tex,NULL,NULL,&w,&h);
    *rect = {rect->x,rect->y,w,h};
    SDL_RenderCopy(rend,tex,NULL,rect);
    SDL_DestroyTexture(tex);
}

void Lines::RenderPrompt(SDL_Renderer* rend,SDL_Rect* rect,TTF_Font* font,string text){
    int w,h;
    rect->x = 0;
    rect->y = 400;
    SDL_Texture *tex = TextureManager::LoadTTF("TTF/alienleague.ttf",font,rend,text);
    SDL_QueryTexture(tex,NULL,NULL,&w,&h);
    *rect = {rect->x,rect->y,w,h};
    SDL_RenderCopy(rend,tex,NULL,rect);
    SDL_DestroyTexture(tex);
}

void Lines::Storyboard(int* currentScene, string Input, bool* isRunning, string* promptText){

    switch(*currentScene){
        case 0:
            if(Input == "PLAY"){
                (*currentScene)++;
            }
            else if(Input == "EXIT"){
                (*isRunning) = false;
            }
            else{
                *(promptText) = "Wrong Input!";
            }
            break;
        default:
            break;
    }

}