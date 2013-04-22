#pragma once

#include "cocos2d.h"
USING_NS_CC;

class HandCardDisplay : public CCSprite
{
    public:
        HandCardDisplay(int x=0, int y=0, float r=0);
        void update(const Card& c);
    
    protected:
        CCSprite bgSprite_;
}


