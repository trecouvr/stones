#include "Utils.h"



bool Utils::touchSprite(const CCTouch* touch, CCSprite* sprite)
{
    CCPoint point = CCDirector::sharedDirector()->convertToGL(touch->getLocationInView());
    return sprite->boundingBox().containsPoint(point);
}


