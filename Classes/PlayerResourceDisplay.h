#pragma once

#include "cocos2d.h"
USING_NS_CC;

#include "Display.h"

class PlayerResourceDisplay : public CCSprite, public Display
{
    public:
        PlayerResourceDisplay(int res=0, int x=0, int y=0);
        ~PlayerResourceDisplay();
        void setRes(int);
        void update(const Action& a, const Player& p, const Player& o);
    
    protected:
        CCLabelTTF* label_;
        int res_;
};


