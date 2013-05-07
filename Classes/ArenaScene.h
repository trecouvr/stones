//
//  ArenaScene.h
//  Stones
//
//  Created by Julien Nicolas on 03/05/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#ifndef Stones_ArenaScene_h
#define Stones_ArenaScene_h
#include "cocos2d.h"
USING_NS_CC;

#include <pthread.h>
#include "game_logic/GameManager.h"


class LayerCocoPlayer;
class LayerHumanCocoPlayer;

class ArenaScene: public CCScene  
{
protected:
	// These 3 attributes have to be dynamically allocated or set to nullptr

	CCLayer* background_Layer_; // layer of the background
	LayerHumanCocoPlayer* player_layer_; // Player_1's UI
	LayerCocoPlayer* opponent_layer_; // Opponent's UI (with restricted access for player_1)
	
	
	
	pthread_t game_thread_;
	GameManager game_manager_;
	
	// Protected method
	
	void startGameManager(void*);
	
	
public:
	// CONSTRUCTORS (Like in cocos, a 2-step constructor approach is adopted)
	
	ArenaScene ():
		background_Layer_(nullptr),player_layer_(nullptr),opponent_layer_(nullptr)
		{} // Default constructor, no logic inside.
	
	void createArenaScene (); // All logic or starting processes must be here
	
	// DESTRUCTOR
	
	virtual ~ArenaScene ();	// Handles the desallocation of the three first attributes
	
	// ACCESSORS
	
	// geters
	
	// seters
	
	void setBackgroundLayer (CCLayer* const b_layer);
	
	// UTILITARY METHODS
	
	
	// Process to be launched during initialization
	
	virtual bool init ();
	
	void update(float t);
	
};



#endif
