#pragma once

#include <vector>

class Card;


class Deck
{
    public:
        Deck(int ncards = 0);
        
        /**
         * Get the first card of the Deck
         * @return Card
         */
        Card draw();
        
        int size() const;
        bool empty() const;
    
    protected:
        std::vector<Card> cards_;
};



