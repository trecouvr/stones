#pragma once

#include <vector>

class Action {
    public:
        enum Action_t { NONE, DRAW, INVOKE_MONSTER_FROM_HAND, SWAP_HAND_CARDS, 
            SWAP_MONSTER_CARDS, START_BATTLE, END_TURN };
        
        Action();
        int getT() const;
        void setT(Action_t t);
        void addData(int v);
        int getData(int i, int default_value = 0) const;
    
    protected:
        Action_t t_;
        std::vector<int> data_;
};

