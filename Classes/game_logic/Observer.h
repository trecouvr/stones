#pragma once

class Event;

class Observer
{
    public:
        Observer();
        virtual ~Observer();
        
        /**
         * Action to perform when this object receives an class::`Event`
         */
        virtual void update(const Event& e) = 0;
};




