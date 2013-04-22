#pragma once

#include "cocos2d.h"
USING_NS_CC;

#include "game_logic/Card.h"

class HandCardDisplay : public CCSprite
{
    public:
        HandCardDisplay(int x=0, int y=0, float r=0);
        ~HandCardDisplay();
        void update(const Card* c);
    
    protected:
        CCLabelTTF* label_;
};


