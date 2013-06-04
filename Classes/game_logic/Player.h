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
        
        /**
         * Remove na card from the area
         */
        void rmMonsterCard(int i);
        
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
         * @return  index of the first non-free emplacement in hand
         * @return  -1 if no free emplacement
         */
        int getNoFreeHandCardIndex() const;
        
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
        
        /**
         * @return  0 if the addition is done
         * @return -1 if monster_in_battle_ is not nullptr
         */

        int addMonsterInBattle (Card& card);
        
        /**
         * @return  0 if the deletion is done
         * @return -1 if monster_in_battle_ is equal to nullptr
         *
         *  Rk : there's just a nullptr assignment here. There's no use of delete.
         */
         
         int rmMonsterInBattle ();
         
        /**
         *  INLINE
         *
         * @return  a pointer to the monster in battle phase
         * @return  nullptr if no monster is in battle phase
         */
        Card* getMonsterInBattle () const;
        
        /**
         *  INLINE
         *
         * returns the graveyard attached to the player
         */
         
        Graveyard& getGraveyard() {return graveyard_;}
        
        int getResRed() const;
        void setResRed(int);
        
        int getResGreen() const;
        void setResGreen(int);
        
        int getResBlue() const;
        void setResBlue(int);
        
        int getResYellow() const;
        void setResYellow(int);
        
        int getRes(int) const;
        void setRes(int,int);
        
        
    protected:
        int hp_;
        int resources_;
        Deck* deck_;
        Card* hand_[5];
        Card* monsters_[5];
        Card* events_or_survivals_[5];
        Graveyard graveyard_;
        
        // Not nullptr if one Player's monster is in the battle phase; it contains this monster 
        
        Card* monster_in_battle_;   
        
        int _getCardTabNullptrIndex(const Card* const* tab) const;
        int _getCardTabCount(const Card* const* tab) const;
        
        int res_red_, res_green_, res_blue_, res_yellow_;
};

