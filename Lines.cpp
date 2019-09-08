#include "Lines.h"

//Number of Letters per line: 42

string Lines::lines[2][8] = {{"This is sample text to check if each line ",
                              "is displaying properly in the text window ",
                              "So that I can actually write a script     "},
                             {"This not the text to check if each line   ",
                              "is displaying something in the text window",
                              "So that I can write a script              "}};

void Lines::RenderLines(SDL_Renderer* rend,SDL_Rect rect,TTF_Font *font,int cur){
        
    for(int i = 0; !lines[cur][i].empty() ; i++){

        SDL_Texture *tex = TextureManager::LoadTTF("TTF/alienleague.ttf",font,rend,lines[cur][i]);
        SDL_RenderCopy(rend,tex,NULL,&rect);

        rect.y +=(35);

    }

}