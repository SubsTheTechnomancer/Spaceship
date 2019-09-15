#include "Leaderboard.h"

string Leaderboard::top[3] = {"","",""};

Client c;

void Leaderboard::update(string name, int time, int location){
    c.run(name,time,location);
}