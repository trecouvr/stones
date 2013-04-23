#include "AreneLayer.h"

#include "game_logic/CardSet.h"
#include "Utils.h"

AreneLayer::AreneLayer() : CCLayer()
{
    setTouchEnabled(true);
    
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
    addChild(pMenu, 1);


    // create background
    color_layer_ = new CCLayerColor;
    color_layer_->initWithColor(ccc4(0, 0, 255, 255));
    addChild(color_layer_, 0);
    
    // init player
    player_.incrementHp(2000);
    Deck* d = new Deck(40);
    player_.setDeck(d);
    
    // init player display
    player_hp_display_.setPosition(ccp(400, 120));
    addChild(&player_hp_display_, 1);
    player_hp_display_.update(player_.getHp());
    
    // init hand displays
    for (int i=0; i<5; ++i)
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
    }
    
    // init monster displays
    for (int i=0; i<5; ++i)
    {
        MonsterDisplay& mdisplay = monster_displays_[i];
        mdisplay.setPosition(ccp(100 + 150*i, 550));
        addChild(&mdisplay, 1);
    }
        
}

AreneLayer::~AreneLayer()
{
}



void AreneLayer::ccTouchesBegan(CCSet* touches, CCEvent* event)
{
    CCLOG("ccTouchBegan");
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
            
            for (int i=0; i<5; ++i)
            {
                HandCardDisplay& hcd = hand_card_displays_[i];
                if (Utils::touchSprite(touch, &hcd))
                {
                    hcd.update(&(CardSet::getInstance().getRandomCard()));
                    hcd.runAction(CCSequence::create(
                        CCScaleBy::create(0.125f, 1.111f),
                        CCScaleBy::create(0.125f, 0.9f),
                        nullptr
                    ));
                }
            }
        }
    }
}


void AreneLayer::draw(CCObject* pSender)
{
    CCLOG("draw");
    
    CCLOG("draw1");
    Card* c = player_.draw();
    CCLOG("draw2");
    if (c != nullptr)
    {
        updateHandDisplays();
    }
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
        CCLOG("update hcd %d", i);
        monster_displays_[i].update(player_.getMonsterCard(i));
    }
}

