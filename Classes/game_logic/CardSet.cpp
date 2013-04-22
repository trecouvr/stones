#include "CardSet.h"

#include <stdlib.h>

CardSet *CardSet::instance_ = 0;

CardSet::CardSet()
{
    cards_["bobo"] = Card(Card::MONSTER, "bobo", 100, 150, 200);
    cards_["baba"] = Card(Card::MONSTER, "baba", 100, 150, 200);
}

CardSet& CardSet::getInstance()
{
	if (CardSet::instance_ == 0)
	{
		CardSet::instance_ = new CardSet();
	}
	return *CardSet::instance_;
}

const Card& CardSet::getRandomCard()
{
	ConstCardMapIterator item = cards_.begin();
	std::advance( item, rand() % cards_.size() );
	
	return item->second;
}


