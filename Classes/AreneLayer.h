#pragma once


#include "cocos2d.h"
USING_NS_CC;

#include "game_logic/Player.h"
#include "PlayerHpDisplay.h"

class AreneLayer : public CCLayer
{
    protected:
        /// The background color layer
        CCLayerColor* color_layer_;
        
        PlayerHpDisplay player_hp_display_;
        
        Player player_;

    public:
        AreneLayer();
        ~AreneLayer();

        CCPoint touchToPoint(CCTouch* touch);

        void ccTouchesBegan(CCSet* touches, CCEvent* event);
        void ccTouchesMoved(CCSet* touches, CCEvent* event);
        void ccTouchesEnded(CCSet* touches, CCEvent* event);
};


