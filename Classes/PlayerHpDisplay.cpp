#include "PlayerHpDisplay.h"

#include <sstream>

PlayerHpDisplay::PlayerHpDisplay(int x, int y)
    : CCSprite()
{
    initWithFile("HpBackground.png");
    setPosition(ccp(x,y));
    
    CCSize size = boundingBox().size;
    label_ = CCLabelTTF::create("0", "Thonburi", 32 );
    label_->setPosition(ccp(size.width/2, size.height/2));
    addChild(label_);
}

void PlayerHpDisplay::update(const int player_hp)
{
    std::stringstream ss;
    ss << player_hp;
    label_->setString(ss.str().c_str());
}

