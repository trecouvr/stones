#include "Utils.h"



static bool Utils::touchSprite(CCTouch* touch, CCSPrite* sprite)
{
    CCPoint point = CCDirector::sharedDirector()->convertToGL(touch->getLocationInView());
    return sprite->boundingBox().containsPoint(point);
}


