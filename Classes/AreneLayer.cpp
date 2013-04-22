#include "AreneLayer.h"

#include "CocoCard.h"

AreneLayer::AreneLayer() : CCLayer()
{
    setTouchEnabled(true);
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCLOG("Size = %f %f", size.width, size.height);
    

    // create white background
    colorLayer = new CCLayerColor;
    colorLayer->initWithColor( ccc4(0, 0, 255, 255) );
    addChild(this->colorLayer, 0);
    
    CocoCard * c = new CocoCard(size.width/2, size.height/2);
    
    // add the sprite as a child to this layer
    addChild(c->getSprite(), 1);
}

AreneLayer::~AreneLayer()
{
}

CCPoint AreneLayer::touchToPoint(CCTouch* touch)
{
    // convert the touch object to a position in our cocos2d space
    return CCDirector::sharedDirector()->convertToGL(touch->getLocationInView());
}


void AreneLayer::ccTouchesBegan(CCSet* touches, CCEvent* event)
{
    CCLOG("ccTouchBegan");
}


void AreneLayer::ccTouchesMoved(CCSet* touches, CCEvent* event)
{
    CCLOG("ccTouchMoved");
}


void AreneLayer::ccTouchesEnded(CCSet* touches, CCEvent* event)
{
    CCLOG("ccTouchEnded");
}


