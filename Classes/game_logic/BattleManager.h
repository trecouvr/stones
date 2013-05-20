//
//  BattleManager.h
//  Stones
//
//  Created by Julien Nicolas on 19/05/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#ifndef Stones_BattleManager_h
#define Stones_BattleManager_h

class Card;
class UserInterface;
class Player;

class BattleManager
{

    
      
public:
    void run (Player& p_atk,Player& p_def);

    // Returns the winner of the fight or nullptr in case of equality

    const Card* const atk (const Card& monster1,const Card& monster2);  
    
    int atk (const Card& monster,Player& o); // Atks the opponent and returns the remaining HPs
    
    void toGraveyard (Card& card,Graveyard& grave); // Sends a card to the graveyard

};








#endif
