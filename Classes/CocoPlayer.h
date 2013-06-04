#pragma once

#include <vector>
#include <pthread.h>

#include "cocos2d.h"
USING_NS_CC;


class Action;
class Player;

class CocoPlayer
{
    public:
        CocoPlayer();
        
        void afterAction(const Action& a, const Player& p, const Player& o, int action_count, bool my_turn);
        
        
        
        /**
         * Try to start an update.
         * @return  true    if and update is needed, lock
         * @return  false   if no update is needed, do nothing
         */
        bool startUpdate();
        /**
         * Unlock the update lock. Warning : use only in mirror of
         * startUpdate.
         */
        void endUpdate();
        
        /**
         * Get the params needed for update, maybe this has to be
         * reviewed now...
         */
        const Action* getLastActionUpdate() const;
        const Player* getLastPlayerUpdate() const;
        const Player* getLastOtherUpdate() const;
        
    protected:
        pthread_mutex_t mutex_;
        pthread_cond_t  cond_;
        
        const Player* p_;
        const Player* o_;
        const Action* a_;
};


