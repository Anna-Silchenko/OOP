#include "GameRule.h"

GameRule::GameRule() : name(""), value("") {}

GameRule::GameRule(const std::string& _name, const std::string& _value)
    : name(_name), value(_value) {}

bool GameRule::validate() const {
    return !name.empty() && !value.empty();
}

std::string GameRule::getName() const {
    return name;
}

std::string GameRule::getValue() const {
    return value;
}

std::string GameRule::getRuleSummary() const {
    if (validate()) {
        return name + ": " + value;
    }
    else {
        return "Invalid Rule";
    }
}
