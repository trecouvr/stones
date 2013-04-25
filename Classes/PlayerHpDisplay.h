#pragma once

#include "cocos2d.h"
USING_NS_CC;

#include "Display.h"

class PlayerHpDisplay : public CCSprite, public Display
{
    public:
        PlayerHpDisplay(int x=0, int y=0);
        ~PlayerHpDisplay();
        void update(const Player& p, const Player& o);
    
    protected:
        CCLabelTTF* label_;
};

