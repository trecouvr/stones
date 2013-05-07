//
//  ArenaScene.cpp
//  Stones
//
//  Created by Julien Nicolas on 03/05/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#include <iostream>
#include "ArenaScene.h"
#include "cocos2d.h"
#include <pthread.h>
#include <unistd.h>

#include "CocoPlayerHuman.h"
#include "CocoPlayerAi.h"
#include "LayerCocoPlayer.h"
#include "LayerHumanCocoPlayer.h"


void ArenaScene::setBackgroundLayer (CCLayer* const b_layer)
{
	this->background_Layer_ = b_layer;
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
	
	CCLayerColor* lc = new CCLayerColor;
	lc->initWithColor (ccc4(0,0,255,255));
	this->background_Layer_ = lc;
	
	// Adding background as a child of the scene
	
	this->addChild(this->background_Layer_,0);
	
	/************* ARENA LAYERS INITIALIZATION **************/
	
	player_layer_ = new LayerHumanCocoPlayer();
	opponent_layer_ = new LayerCocoPlayer();
	
	// Adding layers as child of the scene
	
	this->addChild(this->player_layer_,1);
	this->addChild(this->opponent_layer_,2);
	  
}

// Destructor

ArenaScene::~ArenaScene ()
{	
	// Destruction of the dynamically allocated objects

	if (this->background_Layer_ != nullptr)
		delete this->background_Layer_;
		
	if (this->player_layer_ != nullptr)
		delete this->player_layer_;
		
	if (this->opponent_layer_ != nullptr)
		delete this->opponent_layer_;
		
	// Thread termination
	
	pthread_kill(game_thread_, 15);
    void* ret;
    pthread_join(game_thread_, &ret);
}

// onInit :

bool ArenaScene::init ()
{
	// Super Init first
	
	if (!this->CCScene::init ())	
	{
		std::cerr << std::endl << "CCScene::init error" << std::endl;
		return false;
	}
	
	std::cerr << std::endl << "In ArenaScene::init method" << std::endl;
	
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	
	
	/************* PLAYERS' UI INITIALIZATION **************/
	CocoPlayerHuman* hu = new CocoPlayerHuman();
	CocoPlayerAi* ai = new CocoPlayerAi();
	this->player_layer_->initPlayerInterface(hu, 0.0,1); // TODO fix fuite de mémoire
	this->opponent_layer_->initPlayerInterface(ai, size.height,2);
	
	
	/*************		GAME LOGIC LAUNCHING   **************/
	
	game_manager_ = GameManager(hu, ai);
    pthread_create(&game_thread_, NULL, &start_game_manager, &game_manager_);
	
    player_layer_->schedule( schedule_selector(ArenaScene::update), .2 );
    
    // Start settings are in the game manager
	
	
	return true;
}


void ArenaScene::update(float t)
{
	player_layer_->update(t);
	opponent_layer_->update(t);
}



