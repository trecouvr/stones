#include "Card.h"


Card::Card(Card_t t, std::string name, int cost, int attk, int def)
    : t_(t), name_(name), cost_(cost), attk_(attk), def_(def)
{
    
}


const std::string& Card::getName() const
{
    return name_;
}

