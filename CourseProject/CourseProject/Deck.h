#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

class Deck {
private:
    std::vector<Card> cards;
public:
    Deck();
    void addCard(const Card& card);
    void shuffle();
    bool isEmpty() const;
    Card drawCard();
    unsigned int getDeckSize() const;
};

#endif // DECK_H
