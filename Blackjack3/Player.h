#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Card.h"

class Player {
public:
    Player(bool isDealer);
    void clearHand();
    void addCard(const Card& card);
    int getScore() const;
    bool isBusted() const;

private:
    std::vector<Card> hand;
    int score;
    bool dealer;
};

#endif 
