//
//  GeneralOperators.h
//  Stones
//
//  Created by Julien Nicolas on 20/05/13.
//  Copyright (c) 2013 UTC. All rights reserved.
//

#ifndef Stones_GeneralOperators_h
#define Stones_GeneralOperators_h

// Overloading of some standard operator within the std namespace


namespace std 
{
    bool operator!= (const Card& c1,const Card& c2);
    bool operator== (const Card& c1,const Card& c2);
}


#endif
