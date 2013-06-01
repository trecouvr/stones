#include "CardSet.h"

#include <stdlib.h>

#include "Card.h"

CardSet *CardSet::instance_ = 0;

CardSet::CardSet()
{
    cards_["baleine-danseuse"] = Card(Card::MONSTER, "baleine-danseuse", 100, 300, 400);
    //cards_["baba"] = Card(Card::MONSTER, "baba", 100, 150, 200);
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


