#pragma once

#include <string>
#include <map>

#include "Card.h"


typedef std::map<std::string, Card> CardMap;
typedef std::map<std::string, Card>::iterator CardMapIterator;
typedef std::map<std::string, Card>::const_iterator ConstCardMapIterator;


class CardSet
{
    public:
		static CardSet& getInstance();
		const Card& getRandomCard();

    protected:
        CardSet();
		static CardSet *instance_;
		CardMap cards_;
};


