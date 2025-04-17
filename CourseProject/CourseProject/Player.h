#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Card.h"

class Player {
private:
    std::string name;
    std::vector<Card> hand;
public:
    Player();
    Player(const std::string& _name);
    std::string getName() const;
    void drawCard(class Deck& deck);
    unsigned int getHandSize() const;
    const std::vector<Card>& getHand() const;
};

#endif // PLAYER_H
