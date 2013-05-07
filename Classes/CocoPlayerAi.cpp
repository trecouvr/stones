#include "CocoPlayerAi.h"


CocoPlayerAi::CocoPlayerAi()
    : Ai(), CocoPlayer()
{
    
}

void CocoPlayerAi::afterAction(const Action& a, const Player& p, const Player& o, int action_count)
{
    Ai::afterAction(a,p,o,action_count);
    CocoPlayer::afterAction(a,p,o,action_count);
}

