#pragma once

#include <pthread.h>

#include "cocos2d.h"
USING_NS_CC;

#include "game_logic/GameManager.h"

#include "PlayerHpDisplay.h"
#include "HandCardDisplay.h"
#include "MonsterDisplay.h"

class UserInterface;
class CocoPlayer;

class LayerCocoPlayer : public CCLayer
{
    public:
        LayerCocoPlayer();
		virtual ~LayerCocoPlayer();
        
        void update(float dt);
    
		// Set Player's UI (offset = 0), opponent's when offset != 0 
	
		void initPlayerInterface(CocoPlayer* p, const double offset,const char z_order);

    protected:
        void startGameManager(void*);
        
        PlayerHpDisplay     player_hp_display_;
        HandCardDisplay     hand_card_displays_[5];
        MonsterDisplay      monster_displays_[5];
        
        CocoPlayer* player_;
};


