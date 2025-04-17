#include "RuleParser.h"

RuleParser::RuleParser(const std::string& _filename)
    : filename(_filename) {}

bool RuleParser::loadFile() {
    return true;
}

std::vector<GameRule> RuleParser::parseRules() {
    std::vector<GameRule> rules;
    rules.push_back(GameRule("minPlayers", "2"));
    rules.push_back(GameRule("maxPlayers", "4"));
    return rules;
}
