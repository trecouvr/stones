#include "Ai.h"


#include "Player.h"
#include "Action.h"

Ai::Ai()
{
    
}

void Ai::getAction(Action& a, const Player& p, const Player& o, int action_count)
{
    int i_hand = p.getFreeHandCardIndex();
    int i_monster = p.getFreeMonsterCardIndex();
    if (action_count == 0 && i_hand < 0)
    {
        // piocher si c'est le début du tour
        // et si on a plus de carte
        a.setT(Action::DRAW);
    }
    else if (p.getHandCardCount() > 0 && i_monster > 0)
    {
        // joueur un monstre si on a au moins une carte en main 
        // et un emplacement libre
        a.setT(Action::INVOKE_MONSTER_FROM_HAND);
        a.addData(0);
        a.addData(i_monster);
    }
    else
    {
        a.setT(Action::END_TURN);
    }
}

void Ai::afterAction(const Action& a, const Player& p, const Player& o, int action_count)
{
    
}

