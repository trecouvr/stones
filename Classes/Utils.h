#pragma once

#include "cocos2d.h"
USING_NS_CC;

class Utils
{
    public:
        /**
         * Does the touch point touch the sprite ?
         * Note: dont ask me why but coco does not allow CCSprite to be
         * constant for this check...
         * @param   the touch point
         * @param   the sprite
         * @return  true    The touch point touches the sprite
         * @return  false   The touch point does not touch the sprite
         */
        static bool touchSprite(const CCTouch* touch, CCSprite* sprite);
        
        /**
         * Convert a touch point to the OpenGL position
         * @param touch point
         */
        static CCPoint touchToPoint(CCTouch* touch);
        
        static double distance(CCPoint& a, CCTouch* b);
};

