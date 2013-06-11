#include "MonsterDisplay.h"

#include "game_logic/Player.h"
#include "game_logic/Card.h"

MonsterDisplay::MonsterDisplay(int i, int x, int y, float r)
    : i_(i), CCSprite(), Display(), p_(nullptr)
{
    initWithFile("Test_zone.png");
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
    if (p_ == nullptr)
    {
        p_ = &p;
    }
    
    const Card* c = p.getMonsterCard(i_);
    if (c == nullptr)
    {
        initWithFile("Test_zone.png");
        //label_->setString("empty");
    }
    else
    {
        initWithFile((c->getName()+".min.png").c_str());
        //label_->setString(c->getName().c_str());
    }
}

void MonsterDisplay::setI(int i)
{
    i_ = i;
}

std::string MonsterDisplay::getFilePath() const
{
    if (p_ != nullptr)
    {
        const Card* c = p_->getMonsterCard(i_);
        if (c != nullptr)
        {
            return c->getName()+".png";
        }
    }
    return "";
}


bool MonsterDisplay::isEmpty() const
{
    if (p_ != nullptr)
    {
        return p_->getMonsterCard(i_) == nullptr;
    }
    return true;
}


