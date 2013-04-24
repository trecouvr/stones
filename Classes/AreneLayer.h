#pragma once


#include "cocos2d.h"
USING_NS_CC;

#include "game_logic/Player.h"
#include "PlayerHpDisplay.h"
#include "HandCardDisplay.h"
#include "MonsterDisplay.h"

class AreneLayer : public CCLayer
{
    protected:
        /// The background of the colored layer
        CCLayerColor* color_layer_;
        
        
        Player player_;
        
        PlayerHpDisplay     player_hp_display_;
        HandCardDisplay     hand_card_displays_[5];
        MonsterDisplay      monster_displays_[5];
        
        int lastTouchHand_;
        int lastTouchMonster_;

    public:
        AreneLayer();
        ~AreneLayer();
        
        void draw(CCObject* pSender);
        void updateHandDisplays();
        void updateMonsterDisplays();
        void resetLastTouches();

        void ccTouchesBegan(CCSet* touches, CCEvent* event);
        void ccTouchesMoved(CCSet* touches, CCEvent* event);
        void ccTouchesEnded(CCSet* touches, CCEvent* event);
        void onTouchHandCard(int i);
        void onTouchMonsterCard(int i);
};


