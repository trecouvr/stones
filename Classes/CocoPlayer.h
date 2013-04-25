#pragma once

#include <vector>
#include <pthread.h>

#include "game_logic/UserInterface.h"

#include "Display.h"

class CocoPlayer : public UserInterface
{
    public:
        CocoPlayer();
        
        /**
         * This is a proxy function that does not do anything except
         * block until meth::`sendAction` is called. This is to let the
         * GUI do the job
         */
        Action getAction(const Player& p, const Player& o);
        
        void afterAction(const Player& p, const Player& o);
        
        /**
         * Unblock the meth::`doAction` and make it return the action 
         * type
         */
        void sendAction(Action a);
        
        void addDisplay(Display* d);
    
    protected:
        pthread_mutex_t mutex_;
        pthread_cond_t  cond_;
        Action r_action_;
        std::vector<Display*> displays_;
};


