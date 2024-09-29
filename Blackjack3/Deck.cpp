#include "Deck.h"
#include <algorithm>
#include <random>
#include <chrono>

Deck::Deck() {
    for (int suit = Card::HEARTS; suit <= Card::SPADES; ++suit) {
        for (int rank = Card::TWO; rank <= Card::ACE; ++rank) {
            cards.emplace_back(static_cast<Card::Suit>(suit), static_cast<Card::Rank>(rank));
        }
    }
    shuffle();
}

void Deck::shuffle() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
    currentCardIndex = 0;
}

Card Deck::dealCard() {
    if (currentCardIndex < cards.size()) {
        return cards[currentCardIndex++];
    }
    
    return Card(Card::HEARTS, Card::TWO);
}
