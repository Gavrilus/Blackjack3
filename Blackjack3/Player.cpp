#include "Player.h"

Player::Player(bool isDealer) : dealer(isDealer), score(0) {}

void Player::clearHand() {
    hand.clear();
    score = 0;
}

void Player::addCard(const Card& card) {
    hand.push_back(card);
    score += card.getValue();
    if (score > 21) {
        // Adjust for Aces
        for (auto& c : hand) {
            if (c.getValue() == Card::ACE) {
                score -= 10;  
                if (score <= 21) break;  
            }
        }
    }
}

int Player::getScore() const {
    return score;
}

bool Player::isBusted() const {
    return score > 21;
}
