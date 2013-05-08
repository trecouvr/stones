#pragma once


#include "cocos2d.h"
USING_NS_CC;


class Player;
class Action;

class Display
{
    public:
        Display();
        virtual ~Display();
        virtual void update(const Action& a, const Player& p, const Player& o) = 0;
};


