#include "Observable.h"

#include "Observer.h"


Observable::Observable()
{
    
}

Observable::~Observable()
{
    
}


void Observable::notify(const Event& e)
{
    for (std::vector<Observer*>::iterator it = observers_.begin();
         it != observers_.end(); ++it)
    {
        (*it)->update(e);
    }
}


void Observable::addObserver(Observer* obs)
{
    observers_.push_back(obs);
}

