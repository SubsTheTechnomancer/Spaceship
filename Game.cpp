#include "Game.hpp"
#include "TextureManager.cpp"
#include "Lines.cpp"

using namespace std;

SDL_Texture *textTex;
TTF_Font *font;
SDL_Rect ImgRect, InpRect, PrpRect, textRect;

Game::Game(){
    //Nothing
}

Game::~Game(){
    //Nothing as well
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){
    
    int flags = 0;

    if(fullscreen)
        flags = SDL_WINDOW_FULLSCREEN;
    else
        flags = SDL_WINDOW_SHOWN;

    if(SDL_Init(SDL_INIT_EVERYTHING)==0){

        cout<<"Subsystems Working"<<endl;
        window = SDL_CreateWindow(title,xpos,ypos,width,height,flags);
        tWindow = SDL_CreateWindow(title,xpos+width,ypos,width,height,flags);

        if(window and tWindow){
            cout<<"Window created!"<<endl;
        }

        renderer = SDL_CreateRenderer(window,-1,0);
        trenderer = SDL_CreateRenderer(tWindow,-1,0);

        if(renderer and trenderer){
            SDL_SetRenderDrawColor(renderer,0,0,0,255);
            SDL_SetRenderDrawColor(trenderer,0,0,0,255);
            cout<<"Renderer created!"<<endl;
        }

        isRunning = true;

    }
    else{
        isRunning = false;
    }

    if(IMG_Init(IMG_INIT_PNG)&IMG_INIT_PNG){
        cout<<"SDL Image working!"<<endl;
    }

    if(TTF_Init() != -1){
        cout<<"SDL TTF Working!"<<endl;
    }

    if(SDLNet_Init() != -1){
        cout<<"SDL NET Working!"<<endl;
    }

    fstream fin("Server/Gamedata.dat",fstream::in);
    string s;
    getline(fin,s,'\n');

    if(s[0] == '1') situation = 1;
    else if(s[0] == '2') situation = 2;
    else if(s[0] == '3') situation = 3;

    name = s.substr(2);

    currentScene = 0;
    promptText = "";

    font = TTF_OpenFont("TTF/alienleague.ttf",35);
    
    ImgRect = TextureManager::ImageRect();

    Input = "";

}

void Game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_WINDOWEVENT:
            if(event.window.event == SDL_WINDOWEVENT_CLOSE){
                if(SDL_GetWindowID(tWindow) == event.window.windowID){
                    SDL_DestroyWindow(tWindow);
                    SDL_DestroyRenderer(trenderer);
                    tWindow = NULL;
                    trenderer = NULL;
                }
                else if(SDL_GetWindowID(window) == event.window.windowID){
                    SDL_DestroyWindow(window);
                    SDL_DestroyRenderer(renderer);
                    window = NULL;
                    renderer = NULL;
                }
            }
            break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym){
                case SDLK_BACKSPACE:
                    if(Input != "")
                        Input.pop_back();
                    break;
                case SDLK_SPACE:
                    Input.push_back(' ');
                    break;
                case SDLK_ESCAPE:
                    isRunning = false;
                    break;
                case SDLK_RETURN:
                    Lines::Storyboard(&currentScene,situation,name,Input,&isRunning,&promptText);
                    Input =  "";
                    break;
                default:
                    char a = SDL_GetKeyName(event.key.keysym.sym)[0];
                    Input.push_back(a);
                    break;
            }
            break;
        default:
            break;
    }
}

void Game::update(){
}

void Game::render(){
    SDL_RenderClear(renderer);

    TextureManager::LoadTexture(currentScene,renderer,&ImgRect);

    SDL_RenderPresent(renderer);

    SDL_RenderClear(trenderer);

    Lines::RenderLines(trenderer,&textRect,font,currentScene);  
    Lines::RenderInput(trenderer,&InpRect,font,Input);
    Lines::RenderPrompt(trenderer,&PrpRect,font,promptText);

    SDL_RenderPresent(trenderer);
}

void Game::clean(){

    TTF_CloseFont(font);
    font = NULL;

    SDL_DestroyWindow(window);
    SDL_DestroyWindow(tWindow);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyRenderer(trenderer);
    window = NULL;
    tWindow = NULL;
    trenderer = NULL;
    renderer = NULL;

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}