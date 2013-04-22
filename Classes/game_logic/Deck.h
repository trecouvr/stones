#pragma once

#include <vector>

#include "Card.h"


class Deck
{
    public:
        Deck();
    
    protected:
        std::vector<Card*> cards_;
};



