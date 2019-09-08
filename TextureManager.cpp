#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* filename, SDL_Renderer* rend){
    SDL_Surface* temp = IMG_Load(filename);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(rend,temp);
    SDL_FreeSurface(temp);

    return tex;
}

SDL_Texture* TextureManager::LoadTTF(const char* fontfile,TTF_Font* font, SDL_Renderer* rend, string Text){
    SDL_Surface *textSurface = TTF_RenderText_Blended(font,Text.c_str(),{255,255,255});
    SDL_Texture* textTex = SDL_CreateTextureFromSurface(rend,textSurface);
    SDL_FreeSurface(textSurface);

    return textTex;
}

SDL_Rect TextureManager::ImageRect(){
    SDL_Rect rect;
    rect.x = rect.y = 0;
    rect.w = 800;
    rect.h = 600;
    
    return rect;
}

SDL_Rect TextureManager::TextRect(){
    SDL_Rect rect;
    rect.x = rect.y = 0;
    rect.w = 800;
    rect.h = 30;
    
    return rect;
}