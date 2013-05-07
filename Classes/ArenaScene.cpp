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


void ArenaScene::setBackgroundLayer (CCLayer* const b_layer)
{
	this->background_Layer_ = b_layer;
}


void ArenaScene::setPlayerAreneLayer (AreneLayer* const A_layer)
{
	this->player_layer_ = A_layer;
}

void ArenaScene::setOpponentAreneLayer (AreneLayer* const A_layer)
{
	this->opponent_layer_ = A_layer;
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
	
	this->player_layer_ = new AreneLayer;
	this->opponent_layer_ = new AreneLayer;
	
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
	
	 this->player_layer_->initPlayerInterface(0.0,1);
	 this->opponent_layer_->initPlayerInterface(size.height,2);
	 
	  
	/*************		GAME LOGIC LAUNCHING   **************/
	
	game_manager_ = GameManager(player_layer_->getPlayer (),opponent_layer_->getPlayer());
    pthread_create(&game_thread_, NULL, &start_game_manager, &game_manager_);
	
    this->player_layer_->schedule( schedule_selector(AreneLayer::update), .2 );
    
    // Start settings are in the game manager
	
	
	return true;
}