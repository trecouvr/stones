#pragma once


class Player;

class GameManager
{
    public:
        GameManager();
        GameManager(Player* p1, Player* p2);
        
        /**
         * Launch the game, calling this function will block the current
         * thread
         */
        void run();
        
        /**
         * Is the match finished ?
         */
        bool isFinished() const;
        
    protected:
        /**
         * Wrap the turn of a player
         */
        void runPlayerTurn(Player* p, const Player* o);
        
        /// The two players
        Player* players_[2];
};



