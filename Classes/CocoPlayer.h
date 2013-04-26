#pragma once

#include <pthread.h>

#include "game_logic/Player.h"


class CocoPlayer : public Player
{
    public:
        CocoPlayer();
        
        /**
         * This is a proxy function that does not do anything except
         * block until meth::`sendAction` is called. This is to let the
         * GUI do the job
         */
        Action_t doAction(const Player& other);
        
        /**
         * Unblock the meth::`doAction` and make it return the action 
         * type
         */
        void sendAction(Action_t t);
    
    
    protected:
        pthread_mutex_t mutex_;
        pthread_cond_t  cond_;
        Action_t r_do_action_;
};


