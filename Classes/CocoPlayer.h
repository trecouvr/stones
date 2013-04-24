#pragma once

#include <pthread.h>

#include "game_logic/Player.h"


class CocoPlayer : public Player
{
    public:
        CocoPlayer();
        
        Action_t doAction(const Player& other);
        void sendAction(Action_t t);
    
    
    protected:
        pthread_mutex_t mutex_;
        pthread_cond_t  cond_;
        Action_t r_do_action_;
};


