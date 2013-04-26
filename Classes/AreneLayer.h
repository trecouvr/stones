#pragma once

#include <pthread.h>

#include "cocos2d.h"
USING_NS_CC;

#include "game_logic/GameManager.h"

#include "CocoPlayer.h"
#include "PlayerHpDisplay.h"
#include "HandCardDisplay.h"
#include "MonsterDisplay.h"


class AreneLayer : public CCLayer
{
    public:
        AreneLayer();
        ~AreneLayer();
        
        void update(float dt);
        
        /**
         * Action performed when the user clicks on draw button
         */
        void draw(CCObject* pSender);
        
        /**
         * Reset the pointers to last touched zones
         */
        void resetLastTouches();
        
        void ccTouchesBegan(CCSet* touches, CCEvent* event);
        void ccTouchesMoved(CCSet* touches, CCEvent* event);
        void ccTouchesEnded(CCSet* touches, CCEvent* event);
        void onTouchHandCard(int i);
        void onTouchMonsterCard(int i);
    
    
    protected:
        void startGameManager(void*);
        
        /// The background color layer
        CCLayerColor* color_layer_;
        
        
        CocoPlayer player_;
        
        PlayerHpDisplay     player_hp_display_;
        HandCardDisplay     hand_card_displays_[5];
        MonsterDisplay      monster_displays_[5];
        
        /// Store the last class:`HandCardDisplay` touched
        int lastTouchHand_;
        /// Store the last class:`MonsterDisplay` touched
        int lastTouchMonster_;
        
        pthread_t game_thread_;
        GameManager game_manager_;
};


