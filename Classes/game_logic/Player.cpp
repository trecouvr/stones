#include "Player.h"

#include <algorithm>
using std::fill;

Player::Player(Deck* deck)
    : hp_(0), deck_(deck)
{
    fill(hand_, hand_+5, (Card*)0);
    fill(monsters_, monsters_+5, (Card*)0);
    fill(events_or_survivals_, events_or_survivals_+5, (Card*)0);
}



