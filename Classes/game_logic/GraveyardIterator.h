//
//  GraveyardIterator.h
//  Stones
//
//  Created by Julien Nicolas on 20/05/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#ifndef Stones_GraveyardIterator_h
#define Stones_GraveyardIterator_h

class Card;
class Graveyard;

class GraveyardIterator
{
private:
    Graveyard* grave_; // Points on the aggregate it moves in
    Card* current_element_;
    unsigned int position_;

    // Private Constructors
    
    GraveyardIterator() {}
    GraveyardIterator (Graveyard* const g):grave_(g),current_element_(nullptr),position_(0) {}

    // Friend classes
    
    friend class Graveyard;

public:

    // Standard-movement methods

    Card* first ();
    Card* next ();
    Card* currentElement () const {return current_element_;}
    bool isDone () const;
    
    // Custom-movement methods
    
    unsigned int findCard (Card& card);   // Returns the first occurence of the card "card"

};




#endif
