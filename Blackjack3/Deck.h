#pragma once
#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

class Deck {
public:
    Deck();
    void shuffle();
    Card dealCard();

private:
    std::vector<Card> cards;
    int currentCardIndex;
};

#endif 
