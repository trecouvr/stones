#include "PlayerHpDisplay.h"

#include <sstream>

#include "game_logic/Player.h"


PlayerHpDisplay::PlayerHpDisplay(int x, int y)
    : CCSprite(), Display()
{
    initWithFile("HpBackground.png");
    setPosition(ccp(x,y));
    
    CCSize size = boundingBox().size;
    
    label_ = CCLabelTTF::create("0", "Thonburi", 32 );
    label_->setPosition(ccp(size.width/2, size.height/2));
    addChild(label_);
}

PlayerHpDisplay::~PlayerHpDisplay()
{
    CC_SAFE_RELEASE_NULL(label_);
}

void PlayerHpDisplay::update(const Player& p, const Player& o)
{
    std::stringstream ss;
    ss << p.getHp();
    label_->setString(ss.str().c_str());
}

