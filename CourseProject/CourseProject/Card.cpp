#include "Card.h"

Card::Card() : type(""), value(0) {}

Card::Card(const std::string& _type, int _value)
    : type(_type), value(_value) {}

std::string Card::getType() const {
    return type;
}

int Card::getValue() const {
    return value;
}
