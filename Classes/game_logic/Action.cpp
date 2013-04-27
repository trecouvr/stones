#include "Action.h"


Action::Action() : t_(Action::NONE)
{
    
}

int Action::getT() const
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

