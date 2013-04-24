#pragma once

#include "cocos2d.h"
USING_NS_CC;

class Card;

class MonsterDisplay : public CCSprite
{
    public:
        MonsterDisplay(int x=0, int y=0, float r=0);
        ~MonsterDisplay();
        void update(const Card* c);
    
    protected:
        CCLabelTTF* label_;
};



