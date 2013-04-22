#include "AreneLayer.h"

#include "game_logic/CardSet.h"

AreneLayer::AreneLayer() : CCLayer()
{
    setTouchEnabled(true);
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCLOG("Size = %f %f", size.width, size.height);
    

    // create background
    color_layer_ = new CCLayerColor;
    color_layer_->initWithColor(ccc4(0, 0, 255, 255));
    addChild(color_layer_, 0);
    
    player_.incrementHp(2000);
    
    player_hp_display_.setPosition(ccp(400, 170));
    addChild(&player_hp_display_, 1);
    player_hp_display_.update(player_.getHp());
    
    hand_card_display_.setPosition(ccp(400, 700));
    addChild(&hand_card_display_, 1);
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
    player_.decrementHp(1);
    player_hp_display_.update(player_.getHp());
    hand_card_display_.update(&(CardSet::getInstance().getRandomCard()));
}


