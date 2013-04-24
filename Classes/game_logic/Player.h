#pragma once

class Card;
class Deck;

#include "Action.h"

class Player
{
    public:
        Player(Deck* deck = nullptr);
        ~Player();
        
        /**
         * Shoudl be Overriden, this will be call by the manager during
         * the player turn. This function can perform anything, in case
         * the player wants to launch a battle, the function should 
         * return START_BATTLE, in case he wants to end his turn, the 
         * function should return END_TURN. The function can also return 
         * EMBEDDED in this case, the function will be re-call 
         * immediatly by the manager.
         */
        virtual Action_t doAction(const Player& other) = 0;
        
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
        const Card* getHandCard(int i) const;
        const Card* getMonsterCard(int i) const;
        void setDeck(Deck* deck);
        
    protected:
        int hp_;
        int resources_;
        Deck* deck_;
        Card* hand_[5];
        Card* monsters_[5];
        Card* events_or_survivals_[5];
};

