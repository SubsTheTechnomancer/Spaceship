#include "Lines.h"

//Number of Letters per line: 57

int Lines::time = 0;
int Lines::location = 0;

string Lines::lines[9][10] = {{"                        SPACESHIP                  ",
                              "                                                    ",
                              "                                                    ",
                              "        Welcome to SPACESHIP! Can you survive?      ",
                              "                                                    ",  //0
                              "            Type Play to start the game             ",
                              "                                                    ",
                              "             Type Exit to exit the game             ",
                              "                                                    "},
                             {"                        YOUR ROOM                   ",
                              " You wake up to a dark and silent spaceship hull.   ",
                              " Sirens blare outside the room indicating that      ",
                              " you need to get out of the ship immediately.       ",
                              " Your room door is autolocked, and you don't        ",  //1
                              " quite remember where the spare key is. It is       ",
                              " very dark in your room right now.                  "},
                             {"                        MAIN BAY                    ",
                              " The main bay is bathed in red due to the red sirens",
                              " and you can see the fuselage cracking in multiple  ",
                              " spots. You see the escape pod, your only means of  ",  //2
                              " escape. You'll need the keycard for it though.     ",
                              " You see the medbay's door glitching to your right. ",
                              " There's also the broken command pod to the left.   "},
                             {"                        MED BAY                     ",
                              " Past the broken door, the med bay is in a horrid   ",
                              " state of desrepair. Broken glass and corrugated    ",
                              " meatl is strewn about everywhere, and you can see  ",  //3
                              " blood stains all over the ship. Only one drawer is ",
                              " in working condition, along with the untouched med ",
                              " retrieve system.                                   "},
                             {"                        YOUR ROOM                   ",
                              " You wake up to a dark and silent spaceship hull.   ",
                              " Sirens blare outside the room indicating that      ",
                              " you need to get out of the ship immediately.       ",
                              " Your room door is autolocked, and you don't        ", //4
                              " quite remember where the spare key is. It is       ",
                              " very dark in your room right now, but you see a    ",
                              " horrific sight; a bloodied dead body, spread in the",
                              " middle of the room. Something is afoot.            "},
                             {"                        MAIN BAY                    ",
                              " The main bay is bathed in red due to the red sirens",
                              " and you can see the fuselage cracking in multiple  ",
                              " spots. You see the escape pod, your only means of  ",
                              " escape. You'll need the keycard for it though.     ", //5
                              " You see the medbay's door glitching to your right. ",
                              " Theres also the broken command pod to the left,and ",
                              " to your horror, a torn dead body on the floor.     ",
                              " Something is very wrong over here.                 "},
                             {"                        MED BAY                     ",
                              " Past the broken door, the med bay is in a horrid   ",
                              " state of desrepair. Broken glass and corrugated    ",
                              " metal is strewn about everywhere, and you see a    ", //6
                              " rotting body on the floor. Only one drawer is in   ",
                              " working condition, along with the untouched med    ",
                              " retrieve system. The body indicates impending doom."},
                              {"                   CONGRATULATIONS!                ",
                              "                                                    ",
                              "              You've escaped the spaceship!         ",
                              "                   Type EXIT to exit                ", //7
                              "             Or Type LEADERBOARDS to see            ",
                              "                       top scores.                  ",
                              "                                                    "},
                              {"                       YOU DIED.                   ",
                              "                                                    ",
                              "         You've been killed by.. something.         ",
                              "                   Type EXIT to exit                ", //8
                              "             Or Type LEADERBOARDS to see            ",
                              "                     top scores.                    ",
                              "                                                    "}};

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
    rect->y = 550;
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

bool lights = false, screwdriver = false, firstkey = false, hammer = false, doorunlock = false;
bool keycard = false, metalkey = false, medlocker = false;

void Lines::Storyboard(int* currentScene, int situation, string name, string Input, bool* isRunning, string* promptText){

    switch(*currentScene){
        case 0:
            if(Input == "PLAY"){
                if(situation == 1)
                    (*currentScene) = 4;
                else (*currentScene)++;
                (*promptText) = "";
                time = 0;
            }
            else if(Input == "EXIT"){
                (*isRunning) = false;
            }
            else if(Input == "LEADERBOARD" or Input == "LEADERBOARDS"){
                (*promptText) = "Leaderboards to be implemented\nIn a while";
            }
            else{
                *(promptText) = "Wrong Input!";
            }
            break;
        case 1:
        case 4:
            if(Input == "EXIT"){
                (*isRunning) = false;
            }
            else if((Input == "TURN ON LIGHT") || (Input == "LIGHTS") || (Input == "LIGHT") || (Input == "TURN ON")){
                if(lights == true)
                    (*promptText) = "The lights are already on.";
                else
                    (*promptText) = "You turn the lights on. You can see clearly now.";
                lights = true;
            }
            else if(Input == "LOOK" or Input == "OBSERVE" or Input == "LOOK AROUND"){
                (*promptText) = "You see a drawer, a storage box and an odd panel.";
            }
            else if(Input == "OPEN DRAWER" or Input == "DRAWER"){
                if(lights == false)
                    (*promptText) = "You open the drawer, but it's too dim to see.";
                else if(screwdriver == true)
                    (*promptText) = "There's nothing left in the drawer.";
                else{
                    (*promptText) = "You open the drawer and take a screwdriver from it.";
                    screwdriver = true;
                }
            }
            else if(Input == "OPEN STORAGE BOX" or Input == "OPEN BOX" or Input == "BOX" or Input == "STORAGE BOX"){
                if(lights == false)
                    (*promptText) = "You open the box, but it's too dim to see.";
                else if(hammer == true or situation == 1)
                    (*promptText) = "There's nothing left in the storage box.";
                else{
                    (*promptText) = "You open the box and take the hammer inside it."; 
                }
            }
            else if(Input == "OPEN DOOR" or Input == "DOOR"){
                if(firstkey == false)
                    (*promptText) = "It appears to require the key card for it.";
                else{
                    (*promptText) = "Using the keycard, you unlock and open the door.";
                    doorunlock = true;
                }
            }
            else if(Input == "OPEN PANEL" or Input == "OPEN ODD PANEL" or Input == "PANEL" or Input == "ODD PANEL"){
                if(screwdriver == false)
                    (*promptText) = "The panel is screwed to the floor.";
                else{
                    (*promptText) = "You open the panel to get the keycard for the door.";
                    firstkey = true;
                }
            }
            else if(Input == "GO THROUGH DOOR" or Input == "WALK THROUGH DOOR" or Input == "WALK THROUGH" or Input == "GO THROUGH" or Input == "FORWARD" or Input == "GO"){
                if(doorunlock == false)
                    (*promptText) = "You can't go anywhere without opening the door.";
                else{
                    if(situation == 2)
                        (*currentScene) = 5;
                    else (*currentScene) = 2;
                    (*promptText) = "";
                }
            }
            else if(situation == 1 and (Input == "LOOK AT DEAD BODY" or Input == "LOOK AT BODY" or Input == "SEARCH BODY" or Input == "DEAD BODY" or Input == "BODY" or Input == "SEARCH DEAD BODY")){
                if(hammer == true){
                    (*promptText) = "The body's name tag says "+name+".";
                }
                else{
                    (*promptText) = "You find a hammer on the body and take it.";
                    hammer = true;
                }
            }
            else{
                *(promptText) = "Wrong Input!";
            }
            time++;
            break;
        case 2:
        case 5:
            if(Input == "EXIT")
                (*isRunning) = false;
            else if(Input == "MED BAY" or Input == "GO RIGHT" or Input == "RIGHT" or Input == "GO TO MED BAY"){
                if(situation == 3)
                    (*currentScene) = 6;
                else (*currentScene) = 3;
                (*promptText) = "";
            }
            else if(Input == "LOOK" or Input == "OBSERVE" or Input == "LOOK AROUND"){
                (*promptText) = "You see a command pod and the escape hatch.";
            }
            else if(Input == "COMMAND POD" or Input == "POD" or Input == "LOOK AT COMMAND POD" or Input == "LOOK AT POD"){
                if(situation == 2)
                    (*promptText) = "The pod is damp with a sticky substance,";
                else
                    (*promptText) = "You find a note saying 'MASON XA' on it.";
            }
            else if(Input == "ESCAPE" or Input == "ESCAPE HATCH" or Input == "ESCAPE POD" or Input == "OPEN HATCH" or Input == "OPEN ESCAPE POD" or Input == "OPEN ESCAPE HATCH"){
                if(hammer == false){
                    (*promptText) = "The scanner for the hatch is behind glass.";
                }
                else if(keycard == false){
                    (*promptText) = "You don't have the key for that.";
                }
                else{
                    (*currentScene) = 7;
                    (*promptText) = "";
                }
            }
            else if(situation == 2 and (Input == "LOOK AT DEAD BODY" or Input == "LOOK AT BODY" or Input == "SEARCH BODY" or Input == "DEAD BODY" or Input == "BODY" or Input == "SEARCH DEAD BODY")){
                (*promptText) = "The body's nametag says 'MASON XA'.";
            }
            else if(Input == "GO BACK" or Input == "BACK" or Input == "BACKWARDS"){
                if(situation == 1)
                    (*currentScene) = 4;
                else
                    (*currentScene) = 1;
                (*promptText) = "";
            }
            else{
                *(promptText) = "Wrong Input!";
            }
            time++;
            break;
        case 3:
        case 6:
            if(Input == "EXIT"){
                (*isRunning) = false;
            }
            else if(Input == "MED RETRIEVE" or Input == "RETRIEVE" or Input == "OPEN MED RETRIEVE" or Input == "OPEN RETRIEVE"){
                if(metalkey == false)
                    (*promptText) = "It seems to be locked.";
                else{
                    (*promptText) = "There's a password prompt on it.";
                    medlocker = true;
                }
            }
            else if(medlocker == true){
                if(Input == "GO BACK" or Input == "BACK" or Input == "BACKWARDS"){
                    medlocker = false;
                    (*promptText) = "You leave the med retrieve.";
                }
                if(Input == "TYPE MASON" or Input == "INPUT MASON" or Input == "MASON"){
                    (*promptText) = "The retrieve opens and you get the keycard.";
                    keycard = true;
                    medlocker = false;
                }
                else{
                    (*promptText) = "You can't do anything while in the retrieve.";
                }
            }
            else if(Input == "GO BACK" or Input == "BACK" or Input == "BACKWARDS"){
                if(situation == 2)
                    (*currentScene) = 5;
                else
                    (*currentScene) = 2;
                (*promptText) = "";
            }
            else if(situation == 3 and (Input == "LOOK AT DEAD BODY" or Input == "LOOK AT BODY" or Input == "SEARCH BODY" or Input == "DEAD BODY" or Input == "BODY" or Input == "SEARCH DEAD BODY")){
                if(metalkey == false)
                    (*promptText) = "You take a metal key from the body.";
                else
                    (*promptText) = "The body's nametag says "+name+".";
                metalkey = true;
            }
            else if(Input == "LOOK" or Input == "OBSERVE" or Input == "LOOK AROUND"){
                (*promptText) = "You see a drawer and a med retrieve.";
            }
            else if(Input == "OPEN DRAWER" or Input == "DRAWER"){
                if(situation == 3 or metalkey == true){
                    (*promptText) = "The drawer is empty.";
                }
                else{
                    (*promptText) = "You find a metal key from the drawer.";
                    metalkey = true;
                }
            }
            else{
                (*promptText) = "Wrong Input!";
            }
            break;
        case 7:
        case 8:
            if(Input == "EXIT"){
                (*isRunning) = false;
            }
            else if(Input == "LEADERBOARD" or Input == "LEADERBOARDS"){
                (*promptText) = "Leaderboards to be implemented\nIn a while";
            }
            else{
                (*promptText) = "Wrong Input!";
            }
        default:
            break;
    }
    if(time == 30){
        location = (*currentScene);
        (*currentScene) = 8;
        (*promptText) = "";
        time = 31;
    }
}