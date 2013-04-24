#include "MonsterDisplay.h"

#include "game_logic/Card.h"

MonsterDisplay::MonsterDisplay(int x, int y, float r)
{
    initWithFile("MonsterZone.png");
    setPosition(ccp(x,y));
    setRotation(r);
    
    CCSize size = boundingBox().size;
    
    label_ = CCLabelTTF::create("empty", "Thonburi", 32 );
    label_->setPosition(ccp(size.width/2, size.height/2));
    addChild(label_);
}

MonsterDisplay::~MonsterDisplay()
{
    CC_SAFE_RELEASE_NULL(label_);
}

void MonsterDisplay::update(const Card* c)
{
    if (c == nullptr)
    {
        label_->setString("empty");
    }
    else
    {
        label_->setString(c->getName().c_str());
    }
}


