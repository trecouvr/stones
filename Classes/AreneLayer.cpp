#include "AreneLayer.h"




#include "CocoPlayer.h"
#include "game_logic/CardSet.h"
#include "game_logic/Deck.h"
#include "game_logic/UserInterface.h"
#include "Utils.h"





AreneLayer::AreneLayer() : CCLayer(), player_(nullptr)
{
    
}

// UI displaying


// O N E   P L A Y E R ' S   I N T E R F A C E 
void AreneLayer::initPlayerInterface(CocoPlayer* p, const double offset,const char z_order) // Offset is on y axis
{
    player_ = p;
    
	// If the offset is not nul then the opponent's interface is about to be displayed
	
	double sign = 1;
	
	if (offset > 0)
        sign = -1;
	
	// Enabling touch events
	
	setTouchEnabled(true);
	
	// Init Deck
	
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCLOG("Size = %f %f", size.width, size.height);
    
    CCMenuItemImage *deckItem = CCMenuItemImage::create(
														"Deck.png",
														"DeckSelected.png",
														this,
														menu_selector(AreneLayer::draw) );
    deckItem->setPosition(ccp(700,offset + sign * 400));
    CCMenu* pMenu = CCMenu::create(deckItem, NULL);
    
    CCMenuItemImage *entTurn = CCMenuItemImage::create(
														"Deck.png",
														"DeckSelected.png",
														this,
														menu_selector(AreneLayer::endTurn) );
    entTurn->setPosition(ccp(100,offset + sign * 400));
    pMenu->addChild(entTurn);
    
    pMenu->setPosition(CCPointZero); // Previous : (ccp (0,offset)
    this->addChild(pMenu, z_order);
    
    CCLOG("coucou");
	
    // init player display
	
    player_hp_display_.setPosition(ccp(400, offset + sign * 120));
    this->addChild(&player_hp_display_, z_order); 
    
    // init hand displays
	
    for (int i=0; i<5; ++i)
    {
        HandCardDisplay& hcd = hand_card_displays_[i];
        const double angle = sign * (-90) + 180 * i / 4;
        const double angle_rad = angle * M_PI / 180;
        const double dist_from_center = 200;
        const int x = 400 + sin(angle_rad)*dist_from_center;
        const int y = offset + sign * 120 + cos(angle_rad)*dist_from_center;
		hcd.setI(i);
        hcd.setPosition(ccp(x, y));
        hcd.setRotation(angle);
        this->addChild(&hcd, z_order); 
    }
    
    // init monster displays
	
    for (int i=0; i<5; ++i)
    {
        MonsterDisplay& mdisplay = monster_displays_[i];
		mdisplay.setI(i);
        mdisplay.setPosition(ccp(100 + 150*i, offset + sign * 550));
        addChild(&mdisplay, z_order);
    }
	
}


// Updating

void AreneLayer::update(float t)
{
    if (player_->startUpdate())
    {
        CCLOG("Update arene");
        const Action* a = player_->getLastActionUpdate();
        assert(a != nullptr);
        const Player* p = player_->getLastPlayerUpdate();
        assert(p != nullptr);
        const Player* o = player_->getLastOtherUpdate();
        assert(o != nullptr);
        
        for (int i=0; i<5; ++i)
        {
            hand_card_displays_[i].update(*a, *p, *o);
            monster_displays_[i].update(*a, *p, *o);
        }
        
        player_hp_display_.update(*a, *p, *o);
        
        player_->endUpdate();
    }
}

void AreneLayer::ccTouchesBegan(CCSet* touches, CCEvent* event)
{
    CCLOG("ccTouchBegan");
}


void AreneLayer::ccTouchesMoved(CCSet* touches, CCEvent* event)
{
    //CCLOG("ccTouchMoved");
}


void AreneLayer::ccTouchesEnded(CCSet* touches, CCEvent* event)
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


void AreneLayer::onTouchHandCard(int i)
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


void AreneLayer::onTouchMonsterCard(int i)
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


void AreneLayer::draw(CCObject* pSender)
{
    CCLOG("draw");
    
    Action& a = player_->getAction();
    a.setT(Action::DRAW);
    player_->sendAction();
    resetLastTouches();
}


void AreneLayer::endTurn(CCObject* pSender)
{
    CCLOG("endTurn");
    
    Action& a = player_->getAction();
    a.setT(Action::END_TURN);
    player_->sendAction();
    resetLastTouches();
}


void AreneLayer::resetLastTouches()
{
    lastTouchHand_      = -1;
    lastTouchMonster_   = -1;
}

UserInterface* AreneLayer::getUi()
{
    return this->player;
}

