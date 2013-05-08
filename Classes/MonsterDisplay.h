#pragma once

#include "Display.h"

class Player;

class MonsterDisplay : public CCSprite, public Display
{
    public:
        MonsterDisplay(int i=0, int x=0, int y=0, float r=0);
        ~MonsterDisplay();
        void update(const Action& a, const Player& p, const Player& o);
        
        void setI(int i);
        
    protected:
        CCLabelTTF* label_;
        int i_;
};



