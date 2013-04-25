#pragma once


enum Action_t { DRAW, INVOKE_MONSTER_FROM_HAND, SWAP_HAND_CARDS, 
    SWAP_MONSTER_CARDS, START_BATTLE, END_TURN };

struct Action {
    Action_t t;
    int data[5];
};

