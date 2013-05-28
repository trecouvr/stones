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
#include <vector>

using namespace std;

class Card;

class Graveyard
{
public:
    // Constructors
    
    Graveyard();
    ~Graveyard();
    
    // Accessors
    
    /* Getters*/
    
    Card* getCard (const int i) const;  // Returns a pointer for error tracking 
    unsigned int getNbCards () const;
    
    /* Setters */
    
    void addCard (Card& card);
    void rmCard (Card& card);
    
    // particular methods of iterators
    
    unsigned int findCard (Card& card);   // Returns the first occurence of the card "card"
    
private:    
    vector <Card*> graveyard_; // Contains all defeated monster cards
    unsigned int nb_cards_; // Nb of cards in the array
    
};

#endif
