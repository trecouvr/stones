#pragma once

#include <pthread.h>


#include "game_logic/GameManager.h"

#include "PlayerHpDisplay.h"
#include "HandCardDisplay.h"
#include "MonsterDisplay.h"
#include "PlayerResourceDisplay.h"

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
	
	/**
	 * @return -1 if no touch hand card
	 * @return i index of the hand card if touch
	 */
	int touchHandCard(const CCTouch* touch);
	
	/**
	 * @return -1 if no touch monster card
	 * @return i index of the monster if touch
	 */
	int touchMonsterCard(const CCTouch* touch);

    protected:
        void startGameManager(void*);
        
        PlayerHpDisplay     player_hp_display_;
        HandCardDisplay     hand_card_displays_[5];
        MonsterDisplay      monster_displays_[5];
	PlayerResourceDisplay resource_displays_[4];
        
        CocoPlayer* player_;
};


