#include "AreneLayer.h"




#include "game_logic/CardSet.h"
#include "game_logic/Deck.h"
#include "Utils.h"



void* start_game_manager(void* data)
{
    GameManager* m = (GameManager*)data;
    m->run();
    pthread_exit(NULL);
}

// O N E   P L A Y E R ' S   I N T E R F A C E 

void AreneLayer::initPlayerInterface (const double offset,const char z_order) // Offset is on y axis
{
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
    pMenu->setPosition(CCPointZero); // Previous : (ccp (0,offset)
    addChild(pMenu, z_order);
	
	// init player
	
    player_.incrementHp(2000);
    Deck* d = new Deck(40);
    player_.setDeck(d);
    
    // init player display
    player_hp_display_.setPosition(ccp(400, offset + sign * 120));
    addChild(&player_hp_display_, z_order);
    player_hp_display_.update(player_.getHp());
    
    // init hand displays
	
    for (int i=0; i<5; ++i)
    {
        HandCardDisplay& hcd = hand_card_displays_[i];
        const double angle = -90 + 180 * i / 4;
        const double angle_rad = angle * M_PI / 180;
        const double dist_from_center = 200;
        const int x = 400 + sin(angle_rad)*dist_from_center;
        const int y = offset + sign * 120 + cos(angle_rad)*dist_from_center;
        hcd.setPosition(ccp(x, y));
        hcd.setRotation(angle);
        addChild(&hcd, z_order);
    }
    
    // init monster displays
	
    for (int i=0; i<5; ++i)
    {
        MonsterDisplay& mdisplay = monster_displays_[i];
        mdisplay.setPosition(ccp(100 + 150*i, offset + sign * 550));
        addChild(&mdisplay, z_order);
    }
}



AreneLayer::AreneLayer() : CCLayer()
{
    /*setTouchEnabled(true);
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCLOG("Size = %f %f", size.width, size.height);
    
    CCMenuItemImage *deckItem = CCMenuItemImage::create(
                                        "Deck.png",
                                        "DeckSelected.png",
                                        this,
                                        menu_selector(AreneLayer::draw) );
    deckItem->setPosition(ccp(700, 400));
    CCMenu* pMenu = CCMenu::create(deckItem, NULL);
    pMenu->setPosition(CCPointZero);
    addChild(pMenu, 1);*/


    // create background
    color_layer_ = new CCLayerColor;
    color_layer_->initWithColor(ccc4(0, 0, 255, 255));
    addChild(color_layer_, 0);
    
    // init player
   /* player_.incrementHp(2000);
    Deck* d = new Deck(40);
    player_.setDeck(d);*/
    
    // init player display
    /*player_hp_display_.setPosition(ccp(400, 120));
    addChild(&player_hp_display_, 1);
    player_hp_display_.update(player_.getHp());*/
    
    // init hand displays
    /*for (int i=0; i<5; ++i)
    {
        HandCardDisplay& hcd = hand_card_displays_[i];
        const double angle = -90 + 180 * i / 4;
        const double angle_rad = angle * M_PI / 180;
        const double dist_from_center = 200;
        const int x = 400 + sin(angle_rad)*dist_from_center;
        const int y = 120 + cos(angle_rad)*dist_from_center;
        hcd.setPosition(ccp(x, y));
        hcd.setRotation(angle);
        addChild(&hcd, 1);
    }*/
    
    // init monster displays
    /*for (int i=0; i<5; ++i)
    {
        MonsterDisplay& mdisplay = monster_displays_[i];
        mdisplay.setPosition(ccp(100 + 150*i, 550));
        addChild(&mdisplay, 1);
    }*/
	
	// UI launch test
	
	initPlayerInterface (CCDirector::sharedDirector()->getWinSize().height,1);
    
	// Launch of the game mananger
	
    game_manager_ = GameManager(&player_, &player_);
    pthread_create(&game_thread_, NULL, &start_game_manager, &game_manager_);
}

AreneLayer::~AreneLayer()
{
    pthread_kill(game_thread_, 15);
    void* ret;
    pthread_join(game_thread_, &ret);
}

void AreneLayer::ccTouchesBegan(CCSet* touches, CCEvent* event)
{
    CCLOG("ccTouchBegan");
    player_.sendAction(EMBEDDED);
}


void AreneLayer::ccTouchesMoved(CCSet* touches, CCEvent* event)
{
    CCLOG("ccTouchMoved");
}


void AreneLayer::ccTouchesEnded(CCSet* touches, CCEvent* event)
{
    CCLOG("ccTouchEnded");
    
    for( CCSetIterator it = touches->begin(); it != touches->end(); ++it)
    {
        CCTouch* touch = dynamic_cast<CCTouch*>(*it);
        if(touch)
        {
            if (Utils::touchSprite(touch, &player_hp_display_))
            {
                player_.decrementHp(1);
                player_hp_display_.update(player_.getHp());
            }
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

// Tjr le même problème avec nullptr


void AreneLayer::onTouchHandCard(int i)
{
    HandCardDisplay& hcd = hand_card_displays_[i];
    hcd.runAction(CCSequence::create(
        CCScaleBy::create(0.125f, 1.111f),
        CCScaleBy::create(0.125f, 0.9f),
        0
    ));
    if (lastTouchHand_ >= 0)
    {
        player_.swapHandCards(lastTouchHand_, i);
        updateHandDisplays();
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
        0
    ));
    if (lastTouchHand_ >= 0)
    {
        player_.invokeMonsterFromHand(lastTouchHand_, i);
        updateHandDisplays();
        updateMonsterDisplays();
        resetLastTouches();
    }
    else if (lastTouchMonster_ >= 0)
    {
        player_.swapMonsterCards(lastTouchMonster_, i);
        updateMonsterDisplays();
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
    
    Card* c = player_.draw();
    if (c != 0)
    {
        updateHandDisplays();
    }
    resetLastTouches();
}


void AreneLayer::updateHandDisplays()
{
    for (int i=0; i<5; ++i)
    {
        CCLOG("update hcd %d", i);
        hand_card_displays_[i].update(player_.getHandCard(i));
    }
}

void AreneLayer::updateMonsterDisplays()
{
    for (int i=0; i<5; ++i)
    {
        CCLOG("update md %d", i);
        monster_displays_[i].update(player_.getMonsterCard(i));
    }
}


void AreneLayer::resetLastTouches()
{
    lastTouchHand_      = -1;
    lastTouchMonster_   = -1;
}


