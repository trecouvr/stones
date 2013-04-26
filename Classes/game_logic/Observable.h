#pragma once

#include <vector>


class Event;
class Observer;

class Observable
{
    public:
        Observable();
        virtual ~Observable();
        
        /**
         * Send an class::`Event` to all the observers of this object
         * @param   event
         */
        virtual void notify(const Event&);
        
        /**
         * Add an oberver to this object
         * @param   class::`Observer`
         */
        virtual void addObserver(Observer* obs);
    
    protected:
        std::vector<Observer*> observers_;
};





