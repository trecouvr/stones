#include "CocoPlayer.h"



#include "game_logic/Player.h"
#include "game_logic/Action.h"

CocoPlayer::CocoPlayer()
    : a_(nullptr), p_(nullptr), o_(nullptr)
{
    pthread_mutex_init(&mutex_, NULL);
    pthread_cond_init (&cond_, NULL);
}


void CocoPlayer::afterAction(const Action& a, const Player& p, const Player& o, int action_count)
{
    CCLOG("afterAction %d", a.getT());
    pthread_mutex_lock(&mutex_);
    a_ = new Action(a);
    p_ = &p;
    o_ = &o;
    pthread_mutex_unlock(&mutex_);
}


bool CocoPlayer::startUpdate()
{
    if (a_ != nullptr && p_ != nullptr && o_ != nullptr)
    {
        pthread_mutex_lock(&mutex_);
        return true;
    }
    else
    {
        return false;
    }
}

void CocoPlayer::endUpdate()
{
    delete a_;
    a_ = nullptr;
    p_ = o_ = nullptr;
    pthread_mutex_unlock(&mutex_);
}

const Action* CocoPlayer::getLastActionUpdate() const
{
    return a_;
}

const Player* CocoPlayer::getLastPlayerUpdate() const
{
    return p_;
}

const Player* CocoPlayer::getLastOtherUpdate() const
{
    return o_;
}



