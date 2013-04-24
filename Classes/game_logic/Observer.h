#pragma once

class Event;

class Observer
{
    public:
        Observer();
        virtual ~Observer();
        virtual void update(const Event& e) = 0;
};




