#pragma once

#include "UserInterface.h"

class Ai : public UserInterface
{
    public:
        Ai();
        void getAction(Action& a, const Player& p, const Player& o, int action_count);
        void afterAction(const Action& a, const Player& p, const Player& o, int action_count);
    
    protected:
};

