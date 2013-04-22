#include "SpriteView.h"

using std::string;

SpriteView::SpriteView(string file_path, int x, int y)
{
    sprite_ = new CCSprite;
    sprite_->initWithFile("Card.png");
    sprite_->setPosition(ccp(x, y));
}


SpriteView::~SpriteView()
{
    CC_SAFE_RELEASE_NULL(sprite_);
}


void SpriteView::show()
{
    sprite_->setVisible(true);
}


void SpriteView::hide()
{
    sprite_->setVisible(false);
}


bool SpriteView::isPointIn(const CCPoint & point)
{
    //CCLOG("x=%f y=%f", point.x, point.y);
    //CCLOG("%ld", sprite_->;
    return sprite_->boundingBox().containsPoint(point);
}


const CCPoint& SpriteView::getPosition() const
{
    return sprite_->getPosition();
}


void SpriteView::setPosition(const CCPoint& pos)
{
    return sprite_->setPosition(pos);
}


CCSprite* SpriteView::getSprite()
{
    return sprite_;
}

