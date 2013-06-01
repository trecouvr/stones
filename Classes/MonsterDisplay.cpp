#include "MonsterDisplay.h"

#include "game_logic/Player.h"
#include "game_logic/Card.h"

MonsterDisplay::MonsterDisplay(int i, int x, int y, float r)
    : i_(i), CCSprite(), Display()
{
    initWithFile("MonsterZone.png");
    setPosition(ccp(x,y));
    setRotation(r);
    
    CCSize size = boundingBox().size;
    
    label_ = CCLabelTTF::create("empty", "Thonburi", 32 );
    label_->setPosition(ccp(size.width/2, size.height/2));
    //addChild(label_);
}

MonsterDisplay::~MonsterDisplay()
{
    CC_SAFE_RELEASE_NULL(label_);
}

void MonsterDisplay::update(const Action& a, const Player& p, const Player& o)
{
    const Card* c = p.getMonsterCard(i_);
    if (c == nullptr)
    {
        initWithFile("MonsterZone.png");
        //label_->setString("empty");
    }
    else
    {
        initWithFile(("cards/"+c->getName()+".min.png").c_str());
        //label_->setString(c->getName().c_str());
    }
}

void MonsterDisplay::setI(int i)
{
    i_ = i;
}



