#include "Game.h"

Game::Game(const std::vector<Player>& _players, const Deck& _deck, const std::vector<GameRule>& _rules)
    : players(_players), deck(_deck), rules(_rules), turnIndex(0) {}

void Game::startGame() {
    turnIndex = 0;
}

void Game::nextTurn() {
    turnIndex = (turnIndex + 1) % players.size();
}

Player& Game::getCurrentPlayer() {
    return players[turnIndex];
}

unsigned int Game::getTurnIndex() const {
    return turnIndex;
}
