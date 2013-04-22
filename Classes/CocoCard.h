#pragma once


#include "SpriteView.h"
#include "game_logic/Card.h"

class CocoCard : public Card, public SpriteView
{
    public:
        CocoCard(int x=0, int y=0);
};


