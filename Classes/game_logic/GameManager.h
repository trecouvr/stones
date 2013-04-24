#pragma once


class Player;

class GameManager
{
    public:
        GameManager();
        GameManager(Player* p1, Player* p2);
        
        void run();
        bool isFinish() const;
        
    protected:
        void runPlayerTurn(Player* p, const Player* o);
        
        Player* players_[2];
};



