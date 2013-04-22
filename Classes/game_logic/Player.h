#pragma once

#include "Card.h"
#include "Deck.h"

class Player
{
    public:
        Player(Deck* deck = 0);
    
    protected:
        int hp_;
        int resources_;
        Deck* deck_;
        Card* hand_[5];
        Card* monsters_[5];
        Card* events_or_survivals_[5];
};

