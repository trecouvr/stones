#include "LayerCocoPlayer.h"




#include "CocoPlayer.h"
#include "game_logic/CardSet.h"
#include "game_logic/Deck.h"
#include "game_logic/UserInterface.h"
#include "Utils.h"


LayerCocoPlayer::LayerCocoPlayer() : CCLayer(), player_(nullptr)
{
    
}

LayerCocoPlayer::~LayerCocoPlayer()
{
    
}

// UI displaying


// O N E   P L A Y E R ' S   I N T E R F A C E 
void LayerCocoPlayer::initPlayerInterface(CocoPlayer* p, const double offset,const char z_order) // Offset is on y axis
{
    player_ = p;
    
    // If the offset is not nul then the opponent's interface is about to be displayed
    
    double sign = 1;
    
    if (offset > 0)
        sign = -1;
    
    // Init Deck
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCLOG("Size = %f %f", size.width, size.height);
    
    
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
    
    // init resources
    
    for (int i=0; i<4; ++i)
    {
        PlayerResourceDisplay& rdisplay = resource_displays_[i];
        rdisplay.setRes(i);
        rdisplay.setPosition(ccp(750, offset + sign * (i+1) * 50));
        addChild(&rdisplay, z_order);
    }
    
}


// Updating

void LayerCocoPlayer::update(float t)
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
        for (int i=0; i<4; ++i)
        {
            resource_displays_[i].update(*a, *p, *o);
        }
        
        player_hp_display_.update(*a, *p, *o);
        
        player_->endUpdate();
    }
}


int LayerCocoPlayer::touchHandCard(const CCTouch* touch)
{
    // test touch on hand cards
    for (int i=0; i<5; ++i)
    {
        HandCardDisplay& hcd = hand_card_displays_[i];
        if (Utils::touchSprite(touch, &hcd))
        {
            return i;
        }
    }
    return -1;
}


int LayerCocoPlayer::touchMonsterCard(const CCTouch* touch)
{
    // test touch on monster cards
    for (int i=0; i<5; ++i)
    {
        MonsterDisplay& md = monster_displays_[i];
        if (Utils::touchSprite(touch, &md))
        {
            return i;
        }
    }
    return -1;
}


