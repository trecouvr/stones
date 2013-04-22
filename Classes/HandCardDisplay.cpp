#include "HandCardDisplay.h"


HandCardDisplay::HandCardDisplay(int x, int y, float r)
{
    initWithFile("Card.png");
    setPosition(ccp(x,y));
    
    CCSize size = boundingBox().size;
    
    label_ = CCLabelTTF::create("empty", "Thonburi", 32 );
    label_->setPosition(ccp(size.width/2, size.height/2));
    addChild(label_);
}

HandCardDisplay::~HandCardDisplay()
{
    CC_SAFE_RELEASE_NULL(label_);
}

void HandCardDisplay::update(const Card* c)
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

