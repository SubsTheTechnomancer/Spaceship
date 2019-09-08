#include<bits\stdc++.h>
#include "Game.cpp"

using namespace std;

Game *game = nullptr;

int main(int argv, char** args){

    game = new Game();

    game->init("Spaceship",100,250,800,600,false);

    while(game->running()){
        game->handleEvents();
        game->update();
        game->render();
    }

    game->clean();

    return 0;
}
