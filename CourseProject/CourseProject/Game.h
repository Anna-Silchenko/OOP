#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Player.h"
#include "Deck.h"
#include "GameRule.h"

class Game {
private:
    std::vector<Player> players;
    Deck deck;
    std::vector<GameRule> rules;
    unsigned int turnIndex;
public:
    Game(const std::vector<Player>& players, const Deck& deck, const std::vector<GameRule>& rules);
    void startGame();
    void nextTurn();
    Player& getCurrentPlayer();
    unsigned int getTurnIndex() const;
};

#endif // GAME_H
