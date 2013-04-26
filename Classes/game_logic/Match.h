#pragma once

#include "Player.h"

class Match
{
    public:
        Match(Player* p1, Player* p2);
    
    protected:
        Player* players_[2];
};


