//
//  Graveyard.cpp
//  Stones
//
//  Created by Julien Nicolas on 19/05/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#include "Graveyard.h"
#include "Card.h"

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

// Add a card in the graveyard : expands the size of the array at each new addition

void Graveyard::addCard (Card& card)
{
    if (graveyard_ == nullptr)
    {    
        graveyard_ = new Card*[1];
        graveyard_[0] = &card;
        nb_cards_++;
    }
    else
    {    
        // Recopy the last array in a temp variable
    
        Card** temp = new Card*[nb_cards_];
    
        for (unsigned int i = 0;i < nb_cards_;i++)
            temp[i] = graveyard_[i];
        
        // Delete graveyard_
    
        delete[] graveyard_;
    
        // Creation of a new graveyard able to stores all the cards
    
        nb_cards_++;
        graveyard_ = new Card*[nb_cards_];
    
        // Recopy of the temp array in the graveyard_
    
        for (unsigned int i;i < nb_cards_ - 1;i++)
            graveyard_[i] = temp[i];
        
        // Addition of the new element
    
        graveyard_[nb_cards_-1] = &card;
        
        // Deletion of the temporary array
        
        delete[] temp;
    }
}


// Delete a card from the graveyard, diminishes the size of the array

void Graveyard::rmCard (Card& card)
{
    // searches for the card
    
    unsigned int pos = this->it_->findCard (card);
    
    if (pos != -1) // If there's no error
    {      
        /* Removes the first occurence of the card "card" at position "pos" */
                
        // Copy all the content of the array graveyard_ in a temp array excepted the value at pos "pos"
                               
        Card** temp = new Card*[nb_cards_ - 1];
        
        for (unsigned int i = 0;i < pos;i++)                                    
            temp[i] = graveyard_[i];
                                              
        if (pos != nb_cards_ - 1)   // If the element is not at the end, then copy the rest
            for (unsigned int i = pos+1;i < nb_cards_;i++)
                temp[i-1] = graveyard_[i];
                                                          
        // Deletes the graveyard_
    
        delete[] graveyard_;
                                                                
        // Creation of a well dimensioned graveyard_
                     
        nb_cards_--;
        graveyard_ = new Card*[nb_cards_];
    
        // Copy of the array temp
    
        for (unsigned int i = 0;i < nb_cards_;i++)
            graveyard_[i] = temp[i];
                                                                               
        // Deletion of the temporary array
    
        delete[] temp;
    }
}

