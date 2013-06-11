#include "LayerHumanCocoPlayer.h"




#include "CocoPlayerHuman.h"
#include "Utils.h"




LayerHumanCocoPlayer::LayerHumanCocoPlayer()
    : LayerCocoPlayer(), player_(nullptr), inZoom_(false), inDrag_(false)
{
    resetLastTouches();
}

LayerHumanCocoPlayer::~LayerHumanCocoPlayer()
{
    
}


// UI displaying


// O N E   P L A Y E R ' S   I N T E R F A C E 
void LayerHumanCocoPlayer::initPlayerInterface(CocoPlayerHuman* p, LayerCocoPlayer* o, const double offset,const char z_order) // Offset is on y axis
{
    LayerCocoPlayer::initPlayerInterface(p, offset, z_order);
    
    other_layer_ = o;
    
    player_ = p;
    
    // Enabling touch events
    setTouchEnabled(true);
    
    double sign = 1;
    
    if (offset > 0)
        sign = -1;
    
    // Init Deck
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCLOG("Size = %f %f", size.width, size.height);
    
    CCMenuItemImage *deckItem = CCMenuItemImage::create(
                                                        "Deck.png",
                                                        "DeckSelected.png",
                                                        this,
                                                        menu_selector(LayerHumanCocoPlayer::draw) );
    deckItem->setPosition(ccp(700,offset + sign * 400));
    CCMenu* pMenu = CCMenu::create(deckItem, NULL);
    
    CCMenuItemImage *entTurn = CCMenuItemImage::create(
                                                        "EndTurn.png",
                                                        "EndTurnSelected.png",
                                                        this,
                                                        menu_selector(LayerHumanCocoPlayer::endTurn) );
    entTurn->setPosition(ccp(100,offset + sign * 400));
    pMenu->addChild(entTurn);
    
    pMenu->setPosition(CCPointZero); // Previous : (ccp (0,offset)
    this->addChild(pMenu, z_order);
    
    
    zoom_ = new CCSprite();
    zoom_->setPosition(ccp(size.width/2, size.height/2));
    zoom_->setScale(3);
    this->addChild(zoom_,4);
    zoom_->setVisible(false);
    
    
    dragSprite_ = new CCSprite();
    dragSprite_->setPosition(ccp(size.width/2, size.height/2));
    //dragSprite_->setScale(1.2);
    this->addChild(dragSprite_,4);
    dragSprite_->setVisible(false);
}


void LayerHumanCocoPlayer::ccTouchesBegan(CCSet* touches, CCEvent* event)
{
    CCLOG("ccTouchBegan");
    for( CCSetIterator it = touches->begin(); it != touches->end(); ++it)
    {
        CCTouch* touch = dynamic_cast<CCTouch*>(*it);
        if(touch)
        {
            touchBegan_ = Utils::touchToPoint(touch);
            lastTouchBeganHand_ = touchHandCard(touch);
            lastTouchBeganMonster_ = touchMonsterCard(touch);
            break; // break to allow only single touch
        }
    }
}


void LayerHumanCocoPlayer::ccTouchesMoved(CCSet* touches, CCEvent* event)
{
    for( CCSetIterator it = touches->begin(); it != touches->end(); ++it)
    {
        CCTouch* touch = dynamic_cast<CCTouch*>(*it);
        if (touch)
        {
            if (!inDrag_ and Utils::distance(touchBegan_, touch) > 30)
            {
                startDrag();
            }
            if (inDrag_)
            {
                CCPoint p = Utils::touchToPoint(touch);
                dragSprite_->setPosition(p);
            }
            break;
        }
    }
}


void LayerHumanCocoPlayer::ccTouchesEnded(CCSet* touches, CCEvent* event)
{
    CCLOG("ccTouchEnded");
    
    if (inZoom_)
    {
        zoom_->setVisible(false);
        inZoom_ = false;
    }
    
    
    for( CCSetIterator it = touches->begin(); it != touches->end(); ++it)
    {
        CCTouch* touch = dynamic_cast<CCTouch*>(*it);
        if(touch)
        {
            int i;
            
            i = touchHandCard(touch);
            if (i >= 0)
            {
                onTouchHandCard(i);
            }
            
            i = touchMonsterCard(touch);
            if (i >= 0)
            {
                onTouchMonsterCard(i);
            }
            
            i = other_layer_->touchMonsterCard(touch);
            if (i >= 0)
            {
                onTouchOtherMonsterCard(i);
            }
            break; // break to allow only single touch
        }
    }
    
    if (inDrag_)
    {
        stopDrag();
    }
}

void LayerHumanCocoPlayer::startDrag()
{
    if (lastTouchBeganHand_ < 0 and lastTouchBeganMonster_ < 0) return;
    
    CCLOG("Drag start");
    inDrag_ = true;
    if (lastTouchBeganHand_ >= 0)
    {
        HandCardDisplay& hcd = hand_card_displays_[lastTouchBeganHand_];
        if (!hcd.isEmpty())
        {
            dragSprite_->initWithFile(hcd.getFilePath().c_str());
            dragSprite_->setOpacity(200);
            dragSprite_->setVisible(true);
        }
    }
    else if (lastTouchBeganMonster_ >= 0)
    {
        MonsterDisplay& md = monster_displays_[lastTouchBeganMonster_];
        if (!md.isEmpty())
        {
            dragSprite_->initWithFile(md.getFilePath().c_str());
            dragSprite_->setOpacity(200);
            dragSprite_->setVisible(true);
        }
    }
}

void LayerHumanCocoPlayer::stopDrag()
{
    inDrag_ = false;
    dragSprite_->setVisible(false);
}

void LayerHumanCocoPlayer::onTouchBeganHandCard(int i)
{
    lastTouchBeganHand_ = i;
}

void LayerHumanCocoPlayer::onTouchHandCard(int i)
{
    HandCardDisplay& hcd = hand_card_displays_[i];
    Action& a = player_->getAction();
    if (inDrag_)
    {
        if (lastTouchBeganHand_ >= 0)
        {
            if (lastTouchBeganHand_ == i)
            {
                // il n'a pas bougé, on ne fait rien
            }
            else
            {
                // il tente d'échanger deux cartes de sa main
                Action& a = player_->getAction();
                a.setT(Action::SWAP_HAND_CARDS);
                a.addData(lastTouchBeganHand_);
                a.addData(i);
                player_->sendAction();
            }
        }
        else
        {
            // le joueur a tenté de mettre un monstre du plateau de jeux dans sa main
            // cette action n'est pas permise
        }
        resetLastTouches();
    }
    else
    {
        hcd.runAction(CCSequence::create(
            CCScaleBy::create(0.125f, 1.111f),
            CCScaleBy::create(0.125f, 0.9f),
            nullptr
        ));
        // si il a cliqué sur une carte de sa main avant
        if (lastTouchHand_ >= 0)
        {
            // double click sur la même carte = ZOOM
            if (lastTouchHand_ == i)
            {
                if (!hcd.isEmpty())
                {
                    zoom_->initWithFile(hcd.getFilePath().c_str());
                    zoom_->setVisible(true);
                    inZoom_ = true;
                }
            }
            resetLastTouches();
        }
        else
        {
            resetLastTouches();
            lastTouchHand_ = i;
        }
    }
}

void LayerHumanCocoPlayer::onTouchBeganMonsterCard(int i)
{
    lastTouchBeganMonster_ = i;
}


void LayerHumanCocoPlayer::onTouchMonsterCard(int i)
{
    MonsterDisplay& md = monster_displays_[i];
    Action& a = player_->getAction();
    if (inDrag_)
    {
        // il est partie d'une carte de la main
        // il veut donc invoquer un monstre
        if (lastTouchBeganHand_ >= 0)
        {
            a.setT(Action::INVOKE_MONSTER_FROM_HAND);
            a.addData(lastTouchBeganHand_);
            a.addData(i);
            player_->sendAction();
        }
        // il est parti d'une carte monstre, il veut donc échanger les carte
        else if (lastTouchBeganMonster_ >= 0 and lastTouchBeganMonster_ != i)
        {
            a.setT(Action::SWAP_MONSTER_CARDS);
            a.addData(lastTouchBeganMonster_);
            a.addData(i);
            player_->sendAction();
        }
        resetLastTouches();
    }
    else
    {
        md.runAction(CCSequence::create(
            CCScaleBy::create(0.125f, 1.111f),
            CCScaleBy::create(0.125f, 0.9f),
            nullptr
        ));
        // si il a cliqué sur une carte de monstre avant
        if (lastTouchMonster_ >= 0)
        {
            // double click sur la même carte = ZOOM
            if (lastTouchMonster_ == i)
            {
                if (!md.isEmpty())
                {
                    zoom_->initWithFile(md.getFilePath().c_str());
                    zoom_->setVisible(true);
                    inZoom_ = true;
                }
            }
            resetLastTouches();
        }
        else
        {
            resetLastTouches();
            lastTouchMonster_ = i;
        }
    }
}

void LayerHumanCocoPlayer::onTouchOtherMonsterCard(int i)
{
    CCLOG("want a battle ?");
    Action& a = player_->getAction();
    if (lastTouchMonster_ >= 0)
    {
        a.setT(Action::START_BATTLE);
        a.addData(lastTouchMonster_);
        a.addData(i);
        player_->sendAction();
        resetLastTouches();
    }
    else
    {
        resetLastTouches();
        lastTouchOtherMonster_ = i;
    }
}


void LayerHumanCocoPlayer::draw(CCObject* pSender)
{
    CCLOG("draw");
    
    Action& a = player_->getAction();
    a.setT(Action::DRAW);
    player_->sendAction();
    resetLastTouches();
}


void LayerHumanCocoPlayer::endTurn(CCObject* pSender)
{
    CCLOG("endTurn");
    
    Action& a = player_->getAction();
    a.setT(Action::END_TURN);
    player_->sendAction();
    resetLastTouches();
}


void LayerHumanCocoPlayer::resetLastTouches()
{
    lastTouchHand_          = -1;
    lastTouchBeganHand_     = -1;
    lastTouchMonster_       = -1;
    lastTouchBeganMonster_  = -1;
    lastTouchOtherMonster_  = -1;
}

