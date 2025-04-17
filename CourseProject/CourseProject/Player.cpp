#include "Player.h"
#include "Deck.h"

Player::Player() : name("") {}

Player::Player(const std::string& _name)
    : name(_name) {}

std::string Player::getName() const {
    return name;
}

void Player::drawCard(Deck& deck) {
    if (!deck.isEmpty()) {
        hand.push_back(deck.drawCard());
    }
}

unsigned int Player::getHandSize() const {
    return static_cast<unsigned int>(hand.size());
}

const std::vector<Card>& Player::getHand() const {
    return hand;
}
