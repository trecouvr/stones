//
//  BattleManager.h
//  Stones
//
//  Created by Julien Nicolas on 19/05/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#ifndef Stones_BattleManager_h
#define Stones_BattleManager_h

class Card.h;

class BattleManager
{

    
      
public:
    Card& atk (Card& monster1,Card& monster2);  // Returns the winner of the fight
    void toGraveyard (Card& card,Graveyard& grave); // Sends card to the graveyard

};








#endif
