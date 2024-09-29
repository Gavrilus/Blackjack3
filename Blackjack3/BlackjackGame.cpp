#include "BlackjackGame.h"
#include <iostream>

BlackjackGame::BlackjackGame() : dealer(true), player(false) {}

void BlackjackGame::startGame() {
    deck.shuffle();
    dealer.clearHand();
    player.clearHand();

    initialDeal();

    playerTurn(player);
    if (!player.isBusted()) {
        dealerTurn();
    }

    determineWinner();
}

void BlackjackGame::initialDeal() {
    for (int i = 0; i < 2; ++i) {
        player.addCard(deck.dealCard());
        dealer.addCard(deck.dealCard());
    }
}

void BlackjackGame::playerTurn(Player& player) {
    while (!player.isBusted()) {
        std::cout << "Scoru tau este: " << player.getScore() << ". Dai hit sau stand? (h/s): ";
        char choice;
        std::cin >> choice;
        if (choice == 'h') {
            player.addCard(deck.dealCard());
            std::cout << "Ai tras o carte. Scoru tau nou este: " << player.getScore() << "\n";
        }
        else {
            break;
        }
    }

    if (player.isBusted()) {
        std::cout << "Ai pierdut cu scoru de: " << player.getScore() << "\n";
    }
}

void BlackjackGame::dealerTurn() {
    while (dealer.getScore() < 17) {
        dealer.addCard(deck.dealCard());
    }
    if (dealer.isBusted()) {
        std::cout << "Dealer da bust cu scoru de: " << dealer.getScore() << "\n";
    }
    else {
        std::cout << "Dealer da stand cu scoru de: " << dealer.getScore() << "\n";
    }
}

void BlackjackGame::determineWinner() {
    int dealerScore = dealer.getScore();
    int playerScore = player.getScore();
    if (player.isBusted()) {
        std::cout << "Jucator busted,Dealer castiga\n";
    }
    else if (dealer.isBusted() || playerScore > dealerScore) {
        std::cout << "Jucator castiga cu scor de: " << playerScore << "dealer cu scor de " << dealerScore << "\n";
    }
    else if (playerScore == dealerScore) {
        std::cout << "Push!Jucatorul si dealerul au aceleasi scoruri: " << playerScore << "\n";
    }
    else {
        std::cout << "Dealerul castiga cu scor de: " << dealerScore << "Jucatorul cu scor de: " << playerScore << "\n";
    }
}
