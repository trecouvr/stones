#include "HandCardDisplay.h"

#include "game_logic/Player.h"
#include "game_logic/Card.h"

HandCardDisplay::HandCardDisplay(int i, int x, int y, float r)
    : i_(i), CCSprite(), Display(), p_(nullptr)
{
    initWithFile("Card.png");
    setPosition(ccp(x,y));
    setRotation(r);
    
    CCSize size = boundingBox().size;
    
    label_ = CCLabelTTF::create("empty", "Thonburi", 32 );
    label_->setPosition(ccp(size.width/2, size.height/2));
    //addChild(label_);
    setVisible(false);
}

HandCardDisplay::~HandCardDisplay()
{
    CC_SAFE_RELEASE_NULL(label_);
}

void HandCardDisplay::update(const Action& a, const Player& p, const Player &o)
{
    if (p_ == nullptr)
    {
        p_ = &p;
    }
    
    const Card* c = p.getHandCard(i_);
    if (c == nullptr)
    {
        setVisible(false);
        //label_->setString("empty");
    }
    else
    {
        // TODO afficher le dos de la carte si c'est l'adversaire
        // pour afficher le dos : initWithFile("Card.png"); + setVisible(true);
        //
        initWithFile(getFilePath().c_str());
        setVisible(true);
        //label_->setString(c->getName().c_str());
    }
}

void HandCardDisplay::setI(int i)
{
    i_ = i;
}

std::string HandCardDisplay::getFilePath() const
{
    if (p_ != nullptr)
    {
        const Card* c = p_->getHandCard(i_);
        if (c != nullptr)
        {
            return c->getName()+".png";
        }
    }
    return "";
}


bool HandCardDisplay::isEmpty() const
{
    if (p_ != nullptr)
    {
        return p_->getHandCard(i_) == nullptr;
    }
    return true;
}

