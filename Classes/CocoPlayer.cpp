#include "CocoPlayer.h"



#include "cocos2d.h"
USING_NS_CC;

#include "game_logic/Player.h"

CocoPlayer::CocoPlayer()
    : UserInterface()
{
    pthread_mutex_init(&mutex_, NULL);
    pthread_cond_init (&cond_, NULL);
}

Action CocoPlayer::getAction(const Player& p, const Player& other)
{
    pthread_mutex_lock(&mutex_);
    pthread_cond_wait(&cond_, &mutex_);
    CCLOG("doAction");
    pthread_mutex_unlock(&mutex_);
    return r_action_;
}

void CocoPlayer::afterAction(const Player& p, const Player& o)
{
    for (std::vector<Display*>::iterator it = displays_.begin();
        it != displays_.end(); ++it)
    {
        (*it)->update(p, o);
    }
}

void CocoPlayer::sendAction(Action a)
{
    r_action_ = a;
    pthread_mutex_lock(&mutex_);
    pthread_cond_signal(&cond_);
    pthread_mutex_unlock(&mutex_);
}


