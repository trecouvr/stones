#pragma once


#include "Player.h"

class UserInterface;

class GameManager
{
    public:
        GameManager(UserInterface* ui1 = nullptr, UserInterface* ui2 = nullptr);
        
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
         * 
         *      run = true
         *      while run:
         *          ui.getaction(a,p,o,..)
         *          switch a:
         *              ..
         *              case END_TURN:
         *                  run = false
         *              ..
         *          end switch
         *          ui.afteraction(a,p,o)
         *      end while
         * 
         */
        void runPlayerTurn(UserInterface* ui, Player& p, Player& o);
        
        /// The two players
        Player players_[2];
        
        /// The two uis
        UserInterface* uis_[2];
};



