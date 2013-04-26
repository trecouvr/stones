#pragma once


class Player;
class Action;

class UserInterface
{
    public:
        UserInterface();
        virtual ~UserInterface();
        virtual void getAction(Action& a, const Player& p, const Player& o) = 0;
        virtual void afterAction(const Action& a, const Player& p, const Player& o) = 0;
};

