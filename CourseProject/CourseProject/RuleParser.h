#ifndef RULEPARSER_H
#define RULEPARSER_H

#include <string>
#include <vector>
#include "GameRule.h"

class RuleParser {
private:
    std::string filename;
public:
    RuleParser(const std::string& filename);
    bool loadFile();
    std::vector<GameRule> parseRules();
};

#endif // RULEPARSER_H
