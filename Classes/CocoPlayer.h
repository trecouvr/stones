#pragma once

#include <vector>
#include <pthread.h>

#include "game_logic/UserInterface.h"

class Action;

class CocoPlayer : public UserInterface
{
    public:
        CocoPlayer();
        
        /**
         * This is a proxy function that does not do anything except
         * block until meth::`sendAction` is called. This is to let the
         * GUI do the job
         */
        void getAction(Action& a, const Player& p, const Player& o, int action_count);
        
        void afterAction(const Action& a, const Player& p, const Player& o, int action_count);
        
        /**
         * Unblock the meth::`doAction` and make it return the action 
         * type
         */
        void sendAction();
        
        Action& getAction();
        
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
        Action* r_action_;
        
        const Player* p_;
        const Player* o_;
        const Action* a_;
};


