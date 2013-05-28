//
//  Graveyard.cpp
//  Stones
//
//  Created by Julien Nicolas on 19/05/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#include "Graveyard.h"
#include "Card.h"
#include <vector>
#include "GeneralOperators.h"

Graveyard::Graveyard ()
    : graveyard_(vector<Card*>()),nb_cards_(0)
{}


Graveyard::~Graveyard ()
{
}

// Getters

Card* Graveyard::getCard (const int i) const
{
    if (i > nb_cards_)
        return nullptr;
    else
        return graveyard_[i];
}

unsigned int Graveyard::getNbCards () const
{
    return nb_cards_;
}

// Setters

// Add a card in the graveyard

void Graveyard::addCard (Card& card)
{
   graveyard_.push_back(&card);
}


// Delete a card from the graveyard

void Graveyard::rmCard (Card& card)
{
    vector<Card*>::iterator it = graveyard_.begin();
    vector<Card*>::iterator it_end = graveyard_.end();
    
    
    // gets the first occurence of the card within the graveyard 
    
    while ((*(*it) != card) && (it != it_end))
        it++;
        
    // Erase the element from the graveyard
    
    graveyard_.erase(it);
}

//////////////////////////////////////////////////////
//
//      Custom features for iterators
//
/////////////////////////////////////////////////////


unsigned int Graveyard::findCard(Card& card) 
{
    vector<Card*>::iterator it = graveyard_.begin();
    vector<Card*>::iterator it_end = graveyard_.end();
    
    
    // gets the first occurence of the card within the graveyard 
    
    while ((*(*it) != card) && (it != it_end))
        it++;
        
    return (*(*it)) == card;
}


