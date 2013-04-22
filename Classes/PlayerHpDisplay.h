#pragma once

#include "cocos2d.h"
USING_NS_CC;

class PlayerHpDisplay : public CCSprite
{
    public:
        PlayerHpDisplay(int x=0, int y=0);
        ~PlayerHpDisplay();
        void update(const int player_hp);
    
    protected:
        CCLabelTTF* label_;
};

