#include "CocoPlayerAi.h"


CocoPlayerAi::CocoPlayerAi()
    : Ai(), CocoPlayer()
{
    
}

void CocoPlayerAi::afterAction(const Action& a, const Player& p, const Player& o, int action_count, bool my_turn)
{
    Ai::afterAction(a,p,o,action_count, my_turn);
    CocoPlayer::afterAction(a,p,o,action_count,my_turn);
}

