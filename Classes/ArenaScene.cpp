//
//  ArenaScene.cpp
//  Stones
//
//  Created by Julien Nicolas on 03/05/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#include "ArenaScene.h"

#include "CocoPlayerHuman.h"
#include "CocoPlayerAi.h"
#include "LayerCocoPlayer.h"
#include "LayerHumanCocoPlayer.h"


void ArenaScene::setBackgroundLayer (CCLayer* const b_layer)
{
	background_Layer_ = b_layer;
}




// !!!!!!!!!!! hyper ambigu, pourquoi une fonction (dont tu passes l'adresse) et une méthode? //

void* start_game_manager(void* data)
{
    GameManager* m = (GameManager*)data;
    m->run();
    pthread_exit(NULL);
}

// Content constructor

void ArenaScene::createArenaScene ()
{
	/************* BACKGROUND INITIALIZATION  **************/
	
	/*CCLayerColor* lc = new CCLayerColor;
	lc->initWithColor (ccc4(0,0,255,255));
	background_Layer_ = lc;*/
    
    CCLayer* layer = new CCLayer;
    CCSprite* background = CCSprite::create("fond1.png"); // it's an auto-release object
    background->setAnchorPoint(ccp(0,0));
    background->setPosition(ccp(0,0));
    layer->addChild(background);
    background_Layer_ = layer;
	
	// Adding background as a child of the scene
	
	addChild(background_Layer_,0);
	
	/************* ARENA LAYERS INITIALIZATION **************/
	
	player_layer_ = new LayerHumanCocoPlayer();
	opponent_layer_ = new LayerCocoPlayer();
	
	// Adding layers as child of the scene
	
	addChild(opponent_layer_,1);
	addChild(player_layer_,2);
}

// Destructor

ArenaScene::~ArenaScene ()
{	
	// Destruction of the dynamically allocated objects

	if (background_Layer_ != nullptr)
		delete background_Layer_;
		
	if (player_layer_ != nullptr)
		delete player_layer_;
		
	if (opponent_layer_ != nullptr)
		delete opponent_layer_;
		
	// Thread termination
	
	pthread_kill(game_thread_, 15);
    void* ret;
    pthread_join(game_thread_, &ret);
}

// onInit :

bool ArenaScene::init ()
{
	// Super Init first
	
	if (!CCScene::init ())	
	{
		return false;
	}
	
	
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	
	
	/************* PLAYERS' UI INITIALIZATION **************/
	CocoPlayerHuman* hu = new CocoPlayerHuman(); // TODO delete this
	CocoPlayerAi* ai = new CocoPlayerAi(); // TODO delete this
	opponent_layer_->initPlayerInterface(ai, size.height,2);
	player_layer_->initPlayerInterface(hu, opponent_layer_, 0.0,1);
	
	
	/*************		GAME LOGIC LAUNCHING   **************/
	
	game_manager_ = GameManager(hu, ai);
    pthread_create(&game_thread_, NULL, &start_game_manager, &game_manager_);
	
    schedule( schedule_selector(ArenaScene::update), .1 );
    
    // Start settings are in the game manager
	
	
	return true;
}


void ArenaScene::update(float t)
{
	player_layer_->update(t);
	opponent_layer_->update(t);
}



