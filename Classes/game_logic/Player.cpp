#include "Player.h"

#include <algorithm>

#include "cocos2d.h"
USING_NS_CC;

#include "Card.h"
#include "Deck.h"

Player::Player(Deck* deck, int hp,id_joueur id_j)
    : hp_(hp), deck_(deck),monster_in_battle_(nullptr),
    res_red_(0), res_green_(0), res_blue_(0), res_yellow_(0),id_(id_j)
{
    // Graveyard construction
    
    Graveyard graveyard_;
    
    // Filling of the hand

    std::fill(hand_, hand_+5, nullptr);
    std::fill(monsters_, monsters_+5, nullptr);
    std::fill(events_or_survivals_, events_or_survivals_+5, nullptr);
}

Player::~Player()
{
    // TODO
    //for (Card** it=hand_; it<hand_+5; ++it) if (*it != nullptr) delete *it;
    //for (Card** it=monsters_; it<monsters_+5; ++it) if (*it != nullptr) delete *it;
    //for (Card** it=events_or_survivals_; it<events_or_survivals_+5; ++it) if (*it != nullptr) delete *it;
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


void Player::rmMonsterCard(int i)
{
    // if the index is bad then exit
    if (i <0 || i > 4) return;
    if (monsters_[i] == nullptr) return;
    // remove the monster from the area
    delete monsters_[i];
    monsters_[i] = nullptr;
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


int Player::getNoFreeHandCardIndex() const
{
    for (int i=0; i<5; ++i)
    {
        if (hand_[i] != nullptr)
        {
            return i;
        }
    }
    return -1;
}


int Player::getFreeMonsterCardIndex() const
{
    return _getCardTabNullptrIndex(monsters_);
}


int Player::getHandCardCount() const
{
    return _getCardTabCount(hand_);
}


int Player::getMonsterCardCount() const
{
    return _getCardTabCount(monsters_);
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

int Player::addMonsterInBattle (Card& card)
{
    if (monster_in_battle_ != nullptr)
    {
        monster_in_battle_ = &card;
        return 0;
    }
    else
        return -1;
}

int Player::rmMonsterInBattle ()
{
    if (monster_in_battle_ != nullptr)
    {
        monster_in_battle_ = nullptr;
        return 0;
    }
    else
        return -1;
}


Card* Player::getMonsterInBattle() const 
{
    return monster_in_battle_;
}


int Player::getResRed() const
{
    return res_red_;
}

void Player::setResRed(int v)
{
    res_red_ = v;
}

int Player::getResGreen() const
{
    return res_green_;
}

void Player::setResGreen(int v)
{
    res_green_ = v;
}

int Player::getResBlue() const
{
    return res_blue_;
}

void Player::setResBlue(int v)
{
    res_blue_ = v;
}

int Player::getResYellow() const
{
    return res_yellow_;
}

void Player::setResYellow(int v)
{
    res_yellow_ = v;
}

int Player::getRes(int r) const
{
    switch (r)
    {
        case 0: return res_red_; break;
        case 1: return res_green_; break;
        case 2: return res_blue_; break;
        default: return res_yellow_; break;
    }
}

void Player::setRes(int r, int v)
{
    switch (r)
    {
        case 0: res_red_ = v; break;
        case 1: res_green_ = v; break;
        case 2: res_blue_ = v; break;
        default: res_yellow_ = v; break;
    }
}

const id_joueur Player::getId() const
{
    return id_;
}





