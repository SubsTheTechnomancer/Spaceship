#include "TextureManager.h"

void TextureManager::LoadTexture(int currentScene, SDL_Renderer* rend, SDL_Rect* rect){
    SDL_Surface* temp;
    switch(currentScene){
        case 0:
        case 7:
            temp = IMG_Load("Assets/Main_bg.png");
            break;
        case 1:
            temp = IMG_Load("Assets/Room_1.png");
            break;
        case 2:
            temp = IMG_Load("Assets/Room_2.png");
            break;
        case 3:
            temp = IMG_Load("Assets/Room_3.png");
            break;
        case 4:
            temp = IMG_Load("Assets/Room_1_mod.png");
            break;
        case 5:
            temp = IMG_Load("Assets/Room_2_mod.png");
            break;
        case 6:
            temp = IMG_Load("Assets/Room_3_mod.png");
            break;
        case 8:
            temp = IMG_Load("Assets/Eyes.png");
            break;
        default:
            temp = IMG_Load("Assets/Main_bg.png");
            break;
    }
    SDL_Texture* tex = SDL_CreateTextureFromSurface(rend,temp);
    SDL_FreeSurface(temp);

    SDL_RenderCopy(rend,tex,NULL,rect);
    SDL_DestroyTexture(tex);
}

SDL_Texture* TextureManager::LoadTTF(const char* fontfile,TTF_Font* font, SDL_Renderer* rend, string Text){
    SDL_Surface *temp = TTF_RenderText_Blended(font,Text.c_str(),{255,255,255});
    SDL_Texture* textTex = SDL_CreateTextureFromSurface(rend,temp);
    SDL_FreeSurface(temp);

    return textTex;
}

SDL_Rect TextureManager::ImageRect(){
    SDL_Rect rect;
    rect.x = rect.y = 0;
    rect.w = 800;
    rect.h = 600;
    
    return rect;
}
