#include<bits\stdc++.h>
#include<SDL2/SDL.h>

using namespace std;

int main(int argv, char** args){

    if(SDL_Init(SDL_INIT_EVERYTHING)<0){
        cout<<"SDL could not initialize! SDL Error: "<<SDL_GetError()<<endl;
    }

    system("pause");

    return 0;
}
