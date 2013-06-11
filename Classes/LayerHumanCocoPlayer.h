#pragma once


#include "LayerCocoPlayer.h"


class CocoPlayerHuman;

class LayerHumanCocoPlayer : public LayerCocoPlayer
{
    public:
        LayerHumanCocoPlayer();
		~LayerHumanCocoPlayer();
        
        
		void initPlayerInterface(CocoPlayerHuman* p, LayerCocoPlayer* o, const double offset, const char z_order);
        
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
        void onTouchBeganHandCard(int i);
        void onTouchMonsterCard(int i);
        void onTouchBeganMonsterCard(int i);
        void onTouchOtherMonsterCard(int i);
        
        void startDrag();
        void stopDrag();
        
    protected:
        
        /// Store the last class:`HandCardDisplay` touched
        int lastTouchHand_;
        int lastTouchBeganHand_;
        /// Store the last class:`MonsterDisplay` touched
        int lastTouchMonster_;
        int lastTouchBeganMonster_;
        /// Store the last class:`MonsterDisplay` og the opponent touched
        int lastTouchOtherMonster_;
        
        bool inDrag_;
        CCPoint touchBegan_;
        CCSprite* dragSprite_;
        
        CocoPlayerHuman* player_;
        
        bool inZoom_;
        CCSprite* zoom_;
        
        LayerCocoPlayer* other_layer_;
};



