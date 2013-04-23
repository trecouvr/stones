#include "AreneLayer.h"

#include "game_logic/CardSet.h"
#include "Utils.h"

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
    
    for (int i=0; i<5; ++i) {
        const double angle = -90 + 180 * i / 4;
        const double angle_rad = angle * M_PI / 180;
        const double dist_from_center = 200;
        const int x = 400 + sin(angle_rad)*dist_from_center;
        const int y = 170 + cos(angle_rad)*dist_from_center;
        hand_card_display_[i].setPosition(ccp(x, y));
        hand_card_display_[i].setRotation(angle);
        addChild(&hand_card_display_[i], 1);
    }
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
    
    for( CCSetIterator it = touches->begin(); it != touches->end(); ++it)
    {
        CCTouch* touch = dynamic_cast<CCTouch*>(*it);
        if(touch)
        {
            for (int i=0; i<5; ++i)
            {
                HandCardDisplay& hcd = hand_card_display_[i];
                if (Utils::touchSprite(touch, &hcd))
                {
                    hcd.update(&(CardSet::getInstance().getRandomCard()));
                }
            }
        }
    }
}


