#pragma once

class Player;

class Display
{
    public:
        Display();
        virtual ~Display();
        virtual void update(const Player& p, const Player& o) = 0;
};


