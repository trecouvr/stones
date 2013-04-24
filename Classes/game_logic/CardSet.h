#pragma once

#include <string>
#include <map>

class Card;


typedef std::map<std::string, Card> CardMap;
typedef std::map<std::string, Card>::iterator CardMapIterator;
typedef std::map<std::string, Card>::const_iterator ConstCardMapIterator;

/**
 * Singleton to store all the Cards of Stone
 */
class CardSet
{
    public:
        /**
         * Get the instance of the singleton
         * @return class:`CardSet` singleton instance
         */
		static CardSet& getInstance();
        
        /**
         * Get a random card from the set
         * @return a class:`Card`
         */
		const Card& getRandomCard();

    protected:
        CardSet();
        
        /// class:`CardSet` singleton ptr
		static CardSet *instance_;
        
        /// the set of class::`Card` = Array indexed by the card names
		CardMap cards_;
};


