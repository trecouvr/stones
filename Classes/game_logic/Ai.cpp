#include "Ai.h"


#include "Player.h"
#include "Action.h"

#include "cocos2d.h"
USING_NS_CC;

Ai::Ai()
{
    
}

void Ai::getAction(Action& a, const Player& p, const Player& o, int action_count)
{
    CCLOG("begin ia");
    int i_hand = p.getFreeHandCardIndex();
    int i_monster = p.getFreeMonsterCardIndex();
    CCLOG("%d %d %d %d", action_count, p.getHandCardCount(), i_hand, i_monster);
    if (action_count == 0 && p.getHandCardCount() <= 5)
    {
        CCLOG("piocher");
        // piocher si c'est le début du tour
        // et si on a plus de carte
        a.setT(Action::DRAW);
    }
    else if (action_count < 4 && p.getHandCardCount() > 0 && i_monster >= 0)
    {
        CCLOG("invoke");
        // joueur un monstre si on a au moins une carte en main 
        // et un emplacement libre
        a.setT(Action::INVOKE_MONSTER_FROM_HAND);
        a.addData(p.getNoFreeHandCardIndex());
        a.addData(i_monster);
    }
    else
    {
        CCLOG("end turn");
        a.setT(Action::END_TURN);
    }
    CCLOG("end ia");
}

void Ai::afterAction(const Action& a, const Player& p, const Player& o, int action_count, bool my_turn)
{
    
}

