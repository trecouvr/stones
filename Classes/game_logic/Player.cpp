#include "Player.h"

#include <algorithm>

#include "cocos2d.h"
USING_NS_CC;

#include "Card.h"
#include "Deck.h"

Player::Player(Deck* deck, int hp)
    : hp_(hp), deck_(deck)
{
    std::fill(hand_, hand_+5, nullptr);
    std::fill(monsters_, monsters_+5, nullptr);
    std::fill(events_or_survivals_, events_or_survivals_+5, nullptr);
}

Player::~Player()
{
    for (Card** it=hand_; it<hand_+5; ++it) if (*it != nullptr) delete it;
    for (Card** it=monsters_; it<monsters_+5; ++it) if (*it != nullptr) delete it;
    for (Card** it=events_or_survivals_; it<events_or_survivals_+5; ++it) if (*it != nullptr) delete it;
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
        

void Player::invokeMonsterFromHand(int ihand, int imonster)
{
    // if the indexes are bad then exit
    if (ihand < 0 || ihand > 4 || imonster < 0 or imonster > 4) return;
    
    Card*& hand = hand_[ihand];
    Card*& monster = monsters_[imonster];
    // if the hand position is empty or the monster position is not
    // empty then exit
    if (hand == nullptr || monster != nullptr) return;
    // do the job
    monster = hand;
    hand = nullptr;
}


void Player::swapHandCards(int i, int j)
{
    // if the indexes are bad then exit
    if (i < 0 || i > 4 || j < 0 or j > 4) return;
    // do the job
    std::swap(hand_[i], hand_[j]);
}


void Player::swapMonsterCards(int i, int j)
{
    // if the indexes are bad then exit
    if (i < 0 || i > 4 || j < 0 or j > 4) return;
    // do the job
    std::swap(monsters_[i], monsters_[j]);
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

void Player::setHp(int hp)
{
    hp_ = hp;
}

const Card* Player::getHandCard(int i) const
{
    return hand_[i];
}


const Card* Player::getMonsterCard(int i) const
{
    return monsters_[i];
}


void Player::setDeck(Deck* deck)
{
    deck_ = deck;
}


int Player::getFreeHandCardIndex() const
{
    return _getCardTabNullptrIndex(hand_);
}


int Player::getFreeMonsterCardIndex() const
{
    return _getCardTabNullptrIndex(monsters_);
}


int Player::getHandCardCount() const
{
    _getCardTabCount(hand_);
}


int Player::getMonsterCardCount() const
{
    _getCardTabCount(monsters_);
}

int Player::_getCardTabNullptrIndex(const Card* const* tab) const
{
    for (int i=0; i<5; ++i)
    {
        if (tab[i] == nullptr)
        {
            return i;
        }
    }
    return -1;
}

int Player::_getCardTabCount(const Card* const* tab) const
{
    int c = 0;
    for (int i=0; i<5; ++i)
    {
        c += (tab[i] != nullptr) ? 1 : 0;
    }
    return c;
}



