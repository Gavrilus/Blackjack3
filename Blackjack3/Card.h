#pragma once
#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
public:
    enum Suit { HEARTS, DIAMONDS, CLUBS, SPADES };
    enum Rank { TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK = 10, QUEEN = 10, KING = 10, ACE = 11 };

    Card(Suit suit, Rank rank);
    std::string toString() const;
    int getValue() const;

private:
    Suit suit;
    Rank rank;
};

#endif 
