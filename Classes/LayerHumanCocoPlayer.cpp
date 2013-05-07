#include "LayerHumanCocoPlayer.h"




#include "CocoPlayerHuman.h"
#include "Utils.h"




LayerHumanCocoPlayer::LayerHumanCocoPlayer() : LayerCocoPlayer(), player_(nullptr)
{
    
}

LayerHumanCocoPlayer::~LayerHumanCocoPlayer()
{
    
}


// UI displaying


// O N E   P L A Y E R ' S   I N T E R F A C E 
void LayerHumanCocoPlayer::initPlayerInterface(CocoPlayerHuman* p, const double offset,const char z_order) // Offset is on y axis
{
    LayerCocoPlayer::initPlayerInterface(p, offset, z_order);
    
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
                                                        "Deck.png",
                                                        "DeckSelected.png",
                                                        this,
                                                        menu_selector(LayerHumanCocoPlayer::endTurn) );
    entTurn->setPosition(ccp(100,offset + sign * 400));
    pMenu->addChild(entTurn);
    
    pMenu->setPosition(CCPointZero); // Previous : (ccp (0,offset)
    this->addChild(pMenu, z_order);
}


void LayerHumanCocoPlayer::ccTouchesBegan(CCSet* touches, CCEvent* event)
{
    CCLOG("ccTouchBegan");
}


void LayerHumanCocoPlayer::ccTouchesMoved(CCSet* touches, CCEvent* event)
{
    //CCLOG("ccTouchMoved");
}


void LayerHumanCocoPlayer::ccTouchesEnded(CCSet* touches, CCEvent* event)
{
    CCLOG("ccTouchEnded");
    
    for( CCSetIterator it = touches->begin(); it != touches->end(); ++it)
    {
        CCTouch* touch = dynamic_cast<CCTouch*>(*it);
        if(touch)
        {
            // test touch on hand cards
            for (int i=0; i<5; ++i)
            {
                HandCardDisplay& hcd = hand_card_displays_[i];
                if (Utils::touchSprite(touch, &hcd))
                {
                    onTouchHandCard(i);
                    break;
                }
            }
            // test touch on monster cards
            for (int i=0; i<5; ++i)
            {
                MonsterDisplay& md = monster_displays_[i];
                if (Utils::touchSprite(touch, &md))
                {
                    onTouchMonsterCard(i);
                    break;
                }
            }
        }
        break; // break to allow only single touch
    }
}


void LayerHumanCocoPlayer::onTouchHandCard(int i)
{
    HandCardDisplay& hcd = hand_card_displays_[i];
    hcd.runAction(CCSequence::create(
        CCScaleBy::create(0.125f, 1.111f),
        CCScaleBy::create(0.125f, 0.9f),
        nullptr
    ));
    if (lastTouchHand_ >= 0)
    {
        Action& a = player_->getAction();
        a.setT(Action::SWAP_HAND_CARDS);
        a.addData(lastTouchHand_);
        a.addData(i);
        player_->sendAction();
        resetLastTouches();
    }
    else
    {
        resetLastTouches();
        lastTouchHand_ = i;
    }
}


void LayerHumanCocoPlayer::onTouchMonsterCard(int i)
{
    MonsterDisplay& md = monster_displays_[i];
    md.runAction(CCSequence::create(
        CCScaleBy::create(0.125f, 1.111f),
        CCScaleBy::create(0.125f, 0.9f),
        nullptr
    ));
    Action& a = player_->getAction();
    if (lastTouchHand_ >= 0)
    {
        a.setT(Action::INVOKE_MONSTER_FROM_HAND);
        a.addData(lastTouchHand_);
        a.addData(i);
        player_->sendAction();
        resetLastTouches();
    }
    else if (lastTouchMonster_ >= 0)
    {
        a.setT(Action::SWAP_MONSTER_CARDS);
        a.addData(lastTouchMonster_);
        a.addData(i);
        player_->sendAction();
        resetLastTouches();
    }
    else
    {
        resetLastTouches();
        lastTouchMonster_ = i;
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
    lastTouchHand_      = -1;
    lastTouchMonster_   = -1;
}

