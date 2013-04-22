#pragma once

#include "cocos2d.h"
USING_NS_CC;

class View
{
    public:
        View();
        virtual ~View();
        virtual void show() = 0;
        virtual void hide() = 0;
        virtual bool isPointIn(const CCPoint& point) = 0;
        
};

