//
//  GeneralOperators.cpp
//  Stones
//
//  Created by Julien Nicolas on 20/05/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//


#include "game_logic/Card.h"
#include "GeneralOperators.h"

// One can suppose that two cards are the same or not whether the name is the same or not.

bool std::operator== (const Card& c1,const Card& c2) 
{
        return c1.getName() == c2.getName();
}

bool std::operator!= (const Card& c1,const Card& c2)
{
    return c1.getName() != c2.getName();
}