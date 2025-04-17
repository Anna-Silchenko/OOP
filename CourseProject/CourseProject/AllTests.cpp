#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include "GameRule.h"
#include "RuleParser.h"
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Game.h"

using namespace std;

void testGameRule() {
    GameRule rule("minPlayers", "2");
    assert(rule.validate() == true);
    assert(rule.getName() == "minPlayers");
    assert(rule.getValue() == "2");
    assert(rule.getRuleSummary() == "minPlayers: 2");

    GameRule invalidRule("", "");
    assert(invalidRule.validate() == false);

    cout << "GameRule tests passed." << endl;
}

void testRuleParser() {
    RuleParser parser("dummy_rules_file");
    assert(parser.loadFile() == true);

    auto rules = parser.parseRules();
    assert(rules.size() == 2);
    assert(rules[0].getName() == "minPlayers");
    assert(rules[0].getValue() == "2");
    assert(rules[1].getName() == "maxPlayers");
    assert(rules[1].getValue() == "4");

    cout << "RuleParser tests passed." << endl;
}

void testCard() {
    Card card("Hearts", 10);
    assert(card.getType() == "Hearts");
    assert(card.getValue() == 10);

    cout << "Card tests passed." << endl;
}

void testDeck() {
    Deck deck;
    assert(deck.isEmpty() == true);

    deck.addCard(Card("Spades", 7));
    deck.addCard(Card("Diamonds", 3));
    assert(deck.getDeckSize() == 2);

    deck.shuffle(); 
    assert(deck.getDeckSize() == 2);

    Card drawn = deck.drawCard();
    string type = drawn.getType();
    bool validType = (type == "Spades" || type == "Diamonds");
    assert(validType);
    assert(deck.getDeckSize() == 1);

    cout << "Deck tests passed." << endl;
}

void testPlayer() {
    Deck deck;
    deck.addCard(Card("Clubs", 9));

    Player player("Ivan");
    assert(player.getHandSize() == 0);

    player.drawCard(deck);
    assert(player.getHandSize() == 1);

    auto hand = player.getHand();
    assert(hand[0].getType() == "Clubs");
    assert(hand[0].getValue() == 9);

    cout << "Player tests passed." << endl;
}

void testGame() {
    Player player1("Anna");
    Player player2("Ivan");
    vector<Player> players = { player1, player2 };

    Deck deck;
    deck.addCard(Card("Hearts", 10));
    deck.addCard(Card("Spades", 5));

    vector<GameRule> rules;
    rules.push_back(GameRule("minPlayers", "2"));
    rules.push_back(GameRule("maxPlayers", "4"));

    Game game(players, deck, rules);
    game.startGame();

    assert(game.getTurnIndex() == 0);
    game.nextTurn();
    assert(game.getTurnIndex() == 1);
    game.nextTurn();
    assert(game.getTurnIndex() == 0);

    cout << "Game tests passed." << endl;
}

int main1() {
    cout << "Starting tests..." << endl;
    testGameRule();
    testRuleParser();
    testCard();
    testDeck();
    testPlayer();
    testGame();
    cout << "All tests were locked successfully." << endl;

    // Пауза, чтобы консольное окно не закрывалось мгновенно (по желанию)
    cout << "Press Enter for exit...";
    cin.get();

    return 0;
}
