#ifndef GAMERULE_H
#define GAMERULE_H

#include <string>

class GameRule {
private:
    std::string name;
    std::string value;
public:
    GameRule();
    GameRule(const std::string& name, const std::string& value);
    bool validate() const;
    std::string getName() const;
    std::string getValue() const;
    std::string getRuleSummary() const;
};

#endif // GAMERULE_H
