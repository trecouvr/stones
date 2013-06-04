#pragma once

#include "CocoPlayer.h"
#include "game_logic/UserInterface.h"

class CocoPlayerHuman : public UserInterface, public CocoPlayer
{
    public:
        CocoPlayerHuman();
        
        /**
         * This is a proxy function that does not do anything except
         * block until meth::`sendAction` is called. This is to let the
         * GUI do the job
         */
        void getAction(Action& a, const Player& p, const Player& o, int action_count);
        
        /**
         * Unblock the meth::`doAction` and make it return the action 
         * type
         */
        void sendAction();
        
        void afterAction(const Action& a, const Player& p, const Player& o, int action_count, bool my_turn);
        
        Action& getAction();
    
    protected:
        Action* r_action_;
    
};


