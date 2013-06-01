#include "PlayerResourceDisplay.h"

#include <sstream>

#include "game_logic/Player.h"


PlayerResourceDisplay::PlayerResourceDisplay(int res, int x, int y)
    : CCSprite(), Display(), res_(res)
{
    setRes(res);
    setPosition(ccp(x,y));
    
    CCSize size = boundingBox().size;
    
    label_ = CCLabelTTF::create("0", "Thonburi", 32 );
    label_->setPosition(ccp(size.width/2, size.height/2));
    addChild(label_);
}

void PlayerResourceDisplay::setRes(int res)
{
    std::string s;
    switch (res)
    {
        case 0: s = "red.png"; break;
        case 1: s = "green.png"; break;
        case 2: s = "blue.png"; break;
        default: s = "yellow.png"; break;
    }
    initWithFile(s.c_str());
    res_ = res;
}

PlayerResourceDisplay::~PlayerResourceDisplay()
{
    CC_SAFE_RELEASE_NULL(label_);
}


void PlayerResourceDisplay::update(const Action& a, const Player& p, const Player& o)
{
    std::stringstream ss;
    ss << p.getRes(res_);
    label_->setString(ss.str().c_str());
}


