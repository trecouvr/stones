#include "Deck.h"

#include "Card.h"
#include "CardSet.h"

Deck::Deck(int ncards)
{
    for (int i=0; i<ncards; ++i)
    {
        cards_.push_back(CardSet::getInstance().getRandomCard());
    }
}


Card Deck::draw()
{
    Card c = cards_.back();
    cards_.pop_back();
    return c;
}


int Deck::size() const
{
    return cards_.size();
}


bool Deck::empty() const
{
    return cards_.empty();
}

