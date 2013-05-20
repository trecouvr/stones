//
//  GraveyardIterator.cpp
//  Stones
//
//  Created by Julien Nicolas on 20/05/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#include "Card.h"
#include "GraveyardIterator.h"
#include "Graveyard.h"
#include "GeneralOperators.h"

using namespace std;

GraveyardIterator::GraveyardIterator()
    : grave_(nullptr), current_element_(nullptr), position_(0)
{}

GraveyardIterator::GraveyardIterator (Graveyard* const g)
    : grave_(g), current_element_(nullptr), position_(0)
{}

GraveyardIterator::~GraveyardIterator()
{
}

// Standard operations

Card* GraveyardIterator::first ()
{
    current_element_ = grave_->getCard(0);
    
    return current_element_;
}

Card* GraveyardIterator::next()
{
    if ((position_ + 1) < grave_->getNbCards())
    {
        position_++;
        current_element_ = grave_->getCard(position_);
    }
    
    return current_element_;
}

bool GraveyardIterator::isDone () const
{
    return position_ == (grave_->getNbCards() - 1);
}

// Custom operations

unsigned int GraveyardIterator::findCard(Card& card) 
{
    this->first (); // Putting the iterator at the begining of the aggregat

    // While the card isn't found or the end is not yet reached
    
    while ((*current_element_ != card) && (!this->isDone()))
        this->next();
        
    // Result
    
    if (!this->isDone())
        return position_;
    else
        if (*current_element_ == card)
            return position_;
        else
            return -1;  // error code
}






