//
//  Graveyard.h
//  Stones
//
//  Created by Julien Nicolas on 19/05/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#ifndef Stones_Graveyard_h
#define Stones_Graveyard_h
#include "GraveyardIterator.h"


class Card;

class Graveyard
{
private:    
    Card** graveyard_;   // Contains all defeated monster cards
    unsigned int nb_cards_; // Nb of cards in the array
    GraveyardIterator* it_;

public:
    // Constructors
    
    Graveyard ():graveyard_(nullptr),nb_cards_(0),it_(new GraveyardIterator(this)) {}
    
    // Accessors
    
    /* Getters*/
    
    Card* getCard (const int i) const;  // Returns a pointer for error tracking 
    unsigned int getNbCards () const;
    
    /* Setters */
    
    void addCard (Card& card);
    void rmCard (Card& card);
    
    // Destructors
    
    ~Graveyard () {delete[] graveyard_;delete it_;};
    
};

#endif
