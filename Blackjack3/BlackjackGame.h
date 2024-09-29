#ifndef BLACKJACKGAME_H
#define BLACKJACKGAME_H

#include "Deck.h"
#include "Player.h"

class BlackjackGame {
public:
    BlackjackGame();
    void startGame();

private:
    void initialDeal();
    void playerTurn(Player& player);
    void dealerTurn();
    void determineWinner();

    Deck deck;
    Player dealer;
    Player player;
};

#endif 
