#pragma once


#include "LayerCocoPlayer.h"


class CocoPlayerHuman;

class LayerHumanCocoPlayer : public LayerCocoPlayer
{
    public:
        LayerHumanCocoPlayer();
		~LayerHumanCocoPlayer();
        
        
		void initPlayerInterface(CocoPlayerHuman* p, const double offset,const char z_order);
        
        /**
         * Action performed when the user clicks on draw button
         */
        void draw(CCObject* pSender);
        
        void endTurn(CCObject* pSender);
        
        /**
         * Reset the pointers to last touched zones
         */
        void resetLastTouches();
        
        void ccTouchesBegan(CCSet* touches, CCEvent* event);
        void ccTouchesMoved(CCSet* touches, CCEvent* event);
        void ccTouchesEnded(CCSet* touches, CCEvent* event);
        void onTouchHandCard(int i);
        void onTouchMonsterCard(int i);
        
    protected:
        
        /// Store the last class:`HandCardDisplay` touched
        int lastTouchHand_;
        /// Store the last class:`MonsterDisplay` touched
        int lastTouchMonster_;
        
        CocoPlayerHuman* player_;
        
        bool inZoom_;
        CCSprite* zoom_;
};



