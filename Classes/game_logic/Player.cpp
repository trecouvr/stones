#include "Player.h"

#include <algorithm>

Player::Player(Deck* deck)
    : hp_(0), deck_(deck)
{
    std::fill(hand_, hand_+5, nullptr);
    std::fill(monsters_, monsters_+5, nullptr);
    std::fill(events_or_survivals_, events_or_survivals_+5, nullptr);
}

Card* Player::draw()
{
    for (Card** hand=hand_; hand<hand_+5; ++hand)
    {
        if (*hand == nullptr)
        {
            *hand = new Card(deck_->draw());
            return *hand;
        }
    }
    return nullptr;
}
        

void Player::incrementHp(int v)
{
    hp_ += v;
}

void Player::decrementHp(int v)
{
    hp_ -= v;
}


int Player::getHp() const
{
    return hp_;
}


const Card* Player::getHandCard(int i) const
{
    return hand_[i];
}


void Player::setDeck(Deck* deck)
{
    deck_ = deck;
}





