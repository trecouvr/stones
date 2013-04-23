#pragma once

#include "Card.h"
#include "Deck.h"

class Player
{
    public:
        Player(Deck* deck = nullptr);
        ~Player();
        
        Card* draw();
        void invokeMonsterFromHand(int ihand, int imonster);
        void decrementHp(int v);
        void incrementHp(int v);
        
        int getHp() const;
        const Card* getHandCard(int i) const;
        const Card* getMonsterCard(int i) const;
        void setDeck(Deck* deck);
        
    protected:
        int hp_;
        int resources_;
        Deck* deck_;
        Card* hand_[5];
        Card* monsters_[5];
        Card* events_or_survivals_[5];
};

