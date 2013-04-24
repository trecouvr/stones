#pragma once

#include <vector>


class Event;
class Observer;

class Observable
{
    public:
        Observable();
        virtual ~Observable();
        virtual void notify(const Event&);
        virtual void addObserver(Observer* obs);
    
    protected:
        std::vector<Observer*> observers_;
};





