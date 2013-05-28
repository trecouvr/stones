//
//  BattleManager.cpp
//  Stones
//
//  Created by Julien Nicolas on 20/05/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//


#include "Player.h"
#include "Card.h"
#include "Graveyard.h"
#include "BattleManager.h"
#include "GeneralOperators.h"

using namespace std;

void BattleManager::run (Player& p_atk,Player& p_def)
{
    if (p_def.getMonsterInBattle() != nullptr) // If the attacking has got a target
    {
        const Card* const winner = atk(*(p_atk.getMonsterInBattle()),*(p_def.getMonsterInBattle()));
        
        // Sends the defeated monster to the graveyard
        
        if (*winner == *(p_atk.getMonsterInBattle()))
            toGraveyard(*(p_def.getMonsterInBattle()),p_def.getGraveyard());
            
        else
            if (*winner == *(p_def.getMonsterInBattle()))
                toGraveyard(*(p_atk.getMonsterInBattle()),p_atk.getGraveyard());
                
            else    // Case of equality
            {
                // Places the two monsters in each player's graveyard
                
                toGraveyard(*(p_def.getMonsterInBattle()),p_def.getGraveyard());
                toGraveyard(*(p_atk.getMonsterInBattle()),p_atk.getGraveyard());
            }
    }
    else    // If the attacker has no target then it obviously attacks the opponent
    {
       int hp = atk (*(p_atk.getMonsterInBattle()),p_def);
       
       // Checks if the opponent is dead
       
       if (hp <= 0)
           /* p_atk is the winner */;
            
    }
}

const Card* const BattleManager::atk (const Card& monster1,const Card& monster2)
{
    if (monster1.getAtk() > monster2.getDef())
        return &monster1;
    else
        if (monster1.getAtk() < monster2.getDef())
            return &monster2;
        else
            return nullptr;
}

int BattleManager::atk (const Card& monster,Player& o)
{
    o.decrementHp(monster.getAtk());
    
    return o.getHp();
}

void BattleManager::toGraveyard (Card& card,Graveyard& grave)
{
    grave.addCard(card);
}