#pragma once

#include <string>

class Card
{
    public:
        enum Card_t { MONSTER, EVENT, SURVIVAL };
        Card(Card_t t=MONSTER, std::string name="", int cost=0, 
            int attk=0, int def=0);
    
    protected:
        Card_t t_;
        int cost_;
        std::string name_;
        int attk_;
        int def_;
};


