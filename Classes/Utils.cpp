#include "Utils.h"



bool Utils::touchSprite(const CCTouch* touch, CCSprite* sprite)
{
    CCPoint point = CCDirector::sharedDirector()->convertToGL(touch->getLocationInView());
    return sprite->boundingBox().containsPoint(point);
}


CCPoint Utils::touchToPoint(CCTouch* touch)
{
    // convert the touch object to a position in our cocos2d space
    return CCDirector::sharedDirector()->convertToGL(touch->getLocationInView());
}

