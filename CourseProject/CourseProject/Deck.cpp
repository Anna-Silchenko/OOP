#include "Deck.h"
#include <algorithm>
#include <cstdlib>

Deck::Deck() {
}

void Deck::addCard(const Card& card) {
    cards.push_back(card);
}

void Deck::shuffle() {
    std::random_shuffle(cards.begin(), cards.end());
}

bool Deck::isEmpty() const {
    return cards.empty();
}

Card Deck::drawCard() {
    if (isEmpty()) {
        return Card(); 
    }
    Card drawn = cards.back();
    cards.pop_back();
    return drawn;
}

unsigned int Deck::getDeckSize() const {
    return static_cast<unsigned int>(cards.size());
}
