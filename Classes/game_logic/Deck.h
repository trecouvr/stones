#pragma once

#include <vector>

#include "Card.h"


class Deck
{
    public:
        Deck(int ncards = 0);
        Card draw();
        int size() const;
        bool empty() const;
    
    protected:
        std::vector<Card> cards_;
};



