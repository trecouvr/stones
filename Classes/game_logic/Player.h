#pragma once

class Card;
class Deck;

#include "Action.h"
#include "Graveyard.h"

class Player
{
    public:
        Player(Deck* deck = nullptr, int hp = 0);
        ~Player();
        
        /**
         * Draw a card
         */
        Card* draw();
        
        /**
         * Invoke a monster from the hand == put a card from the hand in
         * the monster zone
         * @param   index of the card in hand
         * @param   index of the card in monster zone
         */
        void invokeMonsterFromHand(int ihand, int imonster);
        
        /**
         * Swap two cards of the hand
         * @param   first card index
         * @param   second card index
         */
        void swapHandCards(int i, int j);
        
        /**
         * Swap two cards of the monster zone
         * @param   first card index
         * @param   second card index
         */
        void swapMonsterCards(int i, int j);
        
        void decrementHp(int v);
        void incrementHp(int v);
        
        int getHp() const;
        void setHp(int hp);
        const Card* getHandCard(int i) const;
        const Card* getMonsterCard(int i) const;
        void setDeck(Deck* deck);
        
        /**
         * @return  index of the first free emplacement in hand
         * @return  -1 if no free emplacement
         */
        int getFreeHandCardIndex() const;
        
        /**
         * @return  index of the first free emplacement in monster zone
         * @return  -1 if no free emplacement
         */
        int getFreeMonsterCardIndex() const;
        
        /**
         * @return  the number of cards in hand
         */
        int getHandCardCount() const;
        
        /**
         * @return  the number of monsters in play (for this player)
         */
        int getMonsterCardCount() const;
        
    protected:
        int hp_;
        int resources_;
        Deck* deck_;
        Card* hand_[5];
        Card* monsters_[5];
        Card* events_or_survivals_[5];
        Graveyard graveyard_;
        
        int _getCardTabNullptrIndex(const Card* const* tab) const;
        int _getCardTabCount(const Card* const* tab) const;
};

