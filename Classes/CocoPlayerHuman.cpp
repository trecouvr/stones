#include "CocoPlayerHuman.h"


CocoPlayerHuman::CocoPlayerHuman()
    : UserInterface(), CocoPlayer()
{
    
}


void CocoPlayerHuman::getAction(Action& a, const Player& p, const Player& other, int action_count)
{
    r_action_ = &a;
    pthread_mutex_lock(&mutex_);
    pthread_cond_wait(&cond_, &mutex_);
    CCLOG("doAction");
    pthread_mutex_unlock(&mutex_);
}




void CocoPlayerHuman::sendAction()
{
    pthread_mutex_lock(&mutex_);
    pthread_cond_signal(&cond_);
    pthread_mutex_unlock(&mutex_);
}


Action& CocoPlayerHuman::getAction()
{
    return *r_action_;
}


void CocoPlayerHuman::afterAction(const Action& a, const Player& p, const Player& o, int action_count)
{
    CocoPlayer::afterAction(a,p,o,action_count);
}

