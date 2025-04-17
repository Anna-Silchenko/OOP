#include "gtest/gtest.h"
#include "../CourseProject/GameRule.h"
#include "../CourseProject/RuleParser.h"
#include "../CourseProject/Card.h"
#include "../CourseProject/Deck.h"
#include "../CourseProject/Player.h"
#include "../CourseProject/Game.h"

TEST(GameRuleTest, ValidRule) {
    GameRule rule("minPlayers", "2");
    EXPECT_TRUE(rule.validate());
    EXPECT_EQ(rule.getName(), "minPlayers");
    EXPECT_EQ(rule.getValue(), "2");
    EXPECT_EQ(rule.getRuleSummary(), "minPlayers: 2");
}

TEST(GameRuleTest, InvalidRule) {
    GameRule invalidRule("", "");
    EXPECT_FALSE(invalidRule.validate());
}

TEST(RuleParserTest, ParseRules) {
    RuleParser parser("dummy_rules_file");
    EXPECT_TRUE(parser.loadFile());

    auto rules = parser.parseRules();
    ASSERT_EQ(rules.size(), 2u); 
    EXPECT_EQ(rules[0].getName(), "minPlayers");
    EXPECT_EQ(rules[0].getValue(), "2");
    EXPECT_EQ(rules[1].getName(), "maxPlayers");
    EXPECT_EQ(rules[1].getValue(), "4");
}

TEST(CardTest, CardProperties) {
    Card card("Hearts", 10);
    EXPECT_EQ(card.getType(), "Hearts");
    EXPECT_EQ(card.getValue(), 10);
}

TEST(DeckTest, DeckOperations) {
    Deck deck;
    EXPECT_TRUE(deck.isEmpty());

    deck.addCard(Card("Spades", 7));
    deck.addCard(Card("Diamonds", 3));
    EXPECT_EQ(deck.getDeckSize(), 2u);

    deck.shuffle();
    EXPECT_EQ(deck.getDeckSize(), 2u);  

    Card drawn = deck.drawCard();
    std::string type = drawn.getType();
    bool validType = (type == "Spades" || type == "Diamonds");
    EXPECT_TRUE(validType);
    EXPECT_EQ(deck.getDeckSize(), 1u);
}

TEST(PlayerTest, DrawCard) {
    Deck deck;
    deck.addCard(Card("Clubs", 9));

    Player player("Ivan");
    EXPECT_EQ(player.getHandSize(), 0u);

    player.drawCard(deck);
    EXPECT_EQ(player.getHandSize(), 1u);

    auto hand = player.getHand();
    EXPECT_EQ(hand[0].getType(), "Clubs");
    EXPECT_EQ(hand[0].getValue(), 9);
}

TEST(GameTest, Turns) {
    Player player1("Anna");
    Player player2("Ivan");
    std::vector<Player> players = { player1, player2 };

    Deck deck;
    deck.addCard(Card("Hearts", 10));
    deck.addCard(Card("Spades", 5));

    std::vector<GameRule> rules;
    rules.push_back(GameRule("minPlayers", "2"));
    rules.push_back(GameRule("maxPlayers", "4"));

    Game game(players, deck, rules);
    game.startGame();

    EXPECT_EQ(game.getTurnIndex(), 0u);
    game.nextTurn();
    EXPECT_EQ(game.getTurnIndex(), 1u);
    game.nextTurn();
    EXPECT_EQ(game.getTurnIndex(), 0u);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
