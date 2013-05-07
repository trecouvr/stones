#pragma once


#include "game_logic/Ai.h"
#include "CocoPlayer.h"


class CocoPlayerAi : public Ai, public CocoPlayer
{
    public:
        CocoPlayerAi();
        void afterAction(const Action& a, const Player& p, const Player& o, int action_count);
};


