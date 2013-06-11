#include "CardSet.h"

#include <stdlib.h>

#include "Card.h"

CardSet *CardSet::instance_ = 0;

CardSet::CardSet()
{
    cards_["Ange_noir"] = Card(Card::MONSTER, "Ange_noir", 100, 300, 400);
    cards_["Archere_lumineuse"] = Card(Card::MONSTER, "Archere_lumineuse", 100, 300, 400);
    cards_["Baleine_danseuse"] = Card(Card::MONSTER, "Baleine_danseuse", 100, 300, 400);
    cards_["Bombe"] = Card(Card::MONSTER, "Bombe", 100, 300, 400);
    cards_["Boule_de_feu"] = Card(Card::MONSTER, "Boule_de_feu", 100, 300, 400);
    cards_["Calmar_geant"] = Card(Card::MONSTER, "Calmar_geant", 100, 300, 400);
    cards_["Centaur_feroce"] = Card(Card::MONSTER, "Centaur_feroce", 100, 300, 400);
    cards_["Chimere_terrestre"] = Card(Card::MONSTER, "Chimere_terrestre", 100, 300, 400);
    cards_["Crane_du_feu"] = Card(Card::MONSTER, "Crane_du_feu", 100, 300, 400);
    cards_["Cyclope"] = Card(Card::MONSTER, "Cyclope", 100, 300, 400);
    cards_["Diable"] = Card(Card::MONSTER, "Diable", 100, 300, 400);
    cards_["Dragon_rouge"] = Card(Card::MONSTER, "Dragon_rouge", 100, 300, 400);
    cards_["Fantome_solitaire"] = Card(Card::MONSTER, "Fantome_solitaire", 100, 300, 400);
    cards_["Fee_enchante"] = Card(Card::MONSTER, "Fee_enchante", 100, 300, 400);
    cards_["Fenix"] = Card(Card::MONSTER, "Fenix", 100, 300, 400);
    cards_["Feu_sacre"] = Card(Card::MONSTER, "Feu_sacre", 100, 300, 400);
    cards_["Flamme_infernale"] = Card(Card::MONSTER, "Flamme_infernale", 100, 300, 400);
    cards_["Gargouille"] = Card(Card::MONSTER, "Gargouille", 100, 300, 400);
    cards_["Grand_pecheur"] = Card(Card::MONSTER, "Grand_pecheur", 100, 300, 400);
    cards_["Guerrier_lumineaux"] = Card(Card::MONSTER, "Guerrier_lumineaux", 100, 300, 400);
    cards_["Hydre_toxique"] = Card(Card::MONSTER, "Hydre_toxique", 100, 300, 400);
    cards_["Le_roi_dauphin"] = Card(Card::MONSTER, "Le_roi_dauphin", 100, 300, 400);
    cards_["Lion_enflamme"] = Card(Card::MONSTER, "Lion_enflamme", 100, 300, 400);
    cards_["Loup_d_or"] = Card(Card::MONSTER, "Loup_d_or", 100, 300, 400);
    cards_["Magicien_Blanc"] = Card(Card::MONSTER, "Magicien_Blanc", 100, 300, 400);
    cards_["Meduse"] = Card(Card::MONSTER, "Meduse", 100, 300, 400);
    cards_["Minotaure_glouton"] = Card(Card::MONSTER, "Minotaure_glouton", 100, 300, 400);
    cards_["Ninja"] = Card(Card::MONSTER, "Ninja", 100, 300, 400);
    cards_["Octopus"] = Card(Card::MONSTER, "Octopus", 100, 300, 400);
    cards_["Pegase"] = Card(Card::MONSTER, "Pegase", 100, 300, 400);
    cards_["Piranhas"] = Card(Card::MONSTER, "Piranhas", 100, 300, 400);
    cards_["Requin_malin"] = Card(Card::MONSTER, "Requin_malin", 100, 300, 400);
    cards_["Robot_fou"] = Card(Card::MONSTER, "Robot_fou", 100, 300, 400);
    cards_["Scorpion"] = Card(Card::MONSTER, "Scorpion", 100, 300, 400);
    cards_["Serpent_de_mer"] = Card(Card::MONSTER, "Serpent_de_mer", 100, 300, 400);
    cards_["Sirene"] = Card(Card::MONSTER, "Sirene", 100, 300, 400);
    cards_["Troll"] = Card(Card::MONSTER, "Troll", 100, 300, 400);
    cards_["Vampire_assoiffe"] = Card(Card::MONSTER, "Vampire_assoiffe", 100, 300, 400);
    cards_["Velociraptor"] = Card(Card::MONSTER, "Velociraptor", 100, 300, 400);
    cards_["Zombie"] = Card(Card::MONSTER, "Zombie", 100, 300, 400);
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


