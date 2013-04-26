#include "HandCardDisplay.h"

#include "game_logic/Player.h"
#include "game_logic/Card.h"

HandCardDisplay::HandCardDisplay(int i, int x, int y, float r)
    : i_(i), CCSprite(), Display()
{
    initWithFile("Card.png");
    setPosition(ccp(x,y));
    setRotation(r);
    
    CCSize size = boundingBox().size;
    
    label_ = CCLabelTTF::create("empty", "Thonburi", 32 );
    label_->setPosition(ccp(size.width/2, size.height/2));
    addChild(label_);
}

HandCardDisplay::~HandCardDisplay()
{
    CC_SAFE_RELEASE_NULL(label_);
}

void HandCardDisplay::update(const Action& a, const Player& p, const Player &o)
{
    const Card* c = p.getHandCard(i_);
    if (c == nullptr)
    {
        label_->setString("empty");
    }
    else
    {
        label_->setString(c->getName().c_str());
    }
}

void HandCardDisplay::setI(int i)
{
    i_ = i;
}

