#include "CocoPlayer.h"



#include "cocos2d.h"
USING_NS_CC;


CocoPlayer::CocoPlayer()
    : Player()
{
    pthread_mutex_init(&mutex_, NULL);
    pthread_cond_init (&cond_, NULL);
}

Action_t CocoPlayer::doAction(const Player& other)
{
    pthread_mutex_lock(&mutex_);
    pthread_cond_wait(&cond_, &mutex_);
    CCLOG("doAction");
    pthread_mutex_unlock(&mutex_);
    return r_do_action_;
}

void CocoPlayer::sendAction(Action_t t)
{
    r_do_action_ = t;
    pthread_mutex_lock(&mutex_);
    pthread_cond_signal(&cond_);
    pthread_mutex_unlock(&mutex_);
}


