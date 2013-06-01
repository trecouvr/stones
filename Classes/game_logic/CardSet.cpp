#include "CardSet.h"

#include <stdlib.h>

#include "Card.h"

CardSet *CardSet::instance_ = 0;

CardSet::CardSet()
{
    cards_["Calmar_geant"] = Card(Card::MONSTER, "Calmar_geant", 100, 300, 400);
    cards_["Baleine_danseuse"] = Card(Card::MONSTER, "Baleine_danseuse", 100, 300, 400);
    cards_["Grand_pecheur"] = Card(Card::MONSTER, "Grand_pecheur", 100, 300, 400);
    cards_["Le_roi_dauphin"] = Card(Card::MONSTER, "Le_roi_dauphin", 100, 300, 400);
    cards_["Octopus"] = Card(Card::MONSTER, "Octopus", 100, 300, 400);
    cards_["Meduse"] = Card(Card::MONSTER, "Meduse", 100, 300, 400);
    cards_["Piranhas"] = Card(Card::MONSTER, "Piranhas", 100, 300, 400);
    cards_["Requin_malin"] = Card(Card::MONSTER, "Requin_malin", 100, 300, 400);
    cards_["Sirene"] = Card(Card::MONSTER, "Sirene", 100, 300, 400);
    cards_["Serpent_de_mer"] = Card(Card::MONSTER, "Serpent_de_mer", 100, 300, 400);
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


