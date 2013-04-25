#pragma once

#include "Action.h"

class Player;

class UserInterface
{
    public:
        UserInterface();
        virtual ~UserInterface();
        virtual Action getAction(const Player& p, const Player& o) = 0;
        virtual void afterAction(const Player& p, const Player& o) = 0;
};

