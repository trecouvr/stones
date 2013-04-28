#include "Action.h"


Action::Action() : t_(NONE)	// Previous value : Action::NONE, but strange so I changed.
{
    
}

Action_t Action::getT() const
{
    return t_;
}

void Action::setT(Action_t t)
{
    t_ = t;
}

void Action::addData(int i)
{
    data_.push_back(i);
}

int Action::getData(int i, int default_value) const
{
    if (data_.size() >= i)
    {
        return data_[i];
    }
    else
    {
        return default_value;
    }
}

