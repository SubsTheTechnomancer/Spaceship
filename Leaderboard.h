#pragma once

#include "Game.hpp"
#include "Client.hpp"

class Leaderboard{
public:
    static string top[3];
    static void update(string name, int time, int location);
};