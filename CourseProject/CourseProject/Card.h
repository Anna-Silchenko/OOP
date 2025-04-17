#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
private:
    std::string type;
    int value;
public:
    Card();
    Card(const std::string& type, int value);
    std::string getType() const;
    int getValue() const;
};

#endif // CARD_H
