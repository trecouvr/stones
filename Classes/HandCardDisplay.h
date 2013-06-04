#pragma once

#include "cocos2d.h"
USING_NS_CC;

#include "Display.h"

class Card;

class HandCardDisplay : public CCSprite, public Display
{
    public:
        HandCardDisplay(int i=0, int x=0, int y=0, float r=0);
        ~HandCardDisplay();
        void update(const Action& a, const Player& p, const Player& o);
        
        void setI(int i);
        CCLabelTTF* label_;
        
        std::string getFilePath() const;
        bool isEmpty() const;
    
    protected:
        int i_;
        const Player* p_;
};


