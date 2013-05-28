#pragma once

#include <string>

class Card
{
    public:
        enum Card_t { MONSTER, EVENT, SURVIVAL };
        Card(Card_t t=MONSTER, std::string name="", int cost=0, 
            int attk=0, int def=0);
        
        // Getters
        
        const std::string& getName() const;
        int getAtk() const {return attk_;}
        int getDef () const {return def_;}
        int getCost () const {return cost_;}
        
        
    protected:
        Card_t t_;
        int cost_;
        std::string name_;
        int attk_;
        int def_;
};


