#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(int currentScene, SDL_Renderer* rend){
    SDL_Surface* temp;
    switch(currentScene){
        case 0:
            temp = IMG_Load("Assets/Main_bg.png");
            break;
        case 1:
            temp = IMG_Load("Assets/Room_1.png");
            break;
        default:
            temp = IMG_Load("Assets/Main_bg.png");
            break;
    }
    SDL_Texture* tex = SDL_CreateTextureFromSurface(rend,temp);
    SDL_FreeSurface(temp);

    return tex;
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
