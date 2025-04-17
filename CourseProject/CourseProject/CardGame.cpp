#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "GameRule.h"
#include "RuleParser.h"
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Game.h"

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));
    RuleParser parser("rules.txt");
    if (parser.loadFile()) {
        cout << "Rules file loaded successfully." << endl;
    }
    else {
        cout << "Error loading rules file. Using default rules." << endl;
    }
    vector<GameRule> rules = parser.parseRules();
    cout << "\nLoaded rules:" << endl;
    for (const auto& rule : rules) {
        cout << "  " << rule.getRuleSummary() << endl;
    }
    Deck deck;
    deck.addCard(Card("Hearts", 10));
    deck.addCard(Card("Spades", 5));
    deck.addCard(Card("Clubs", 8));
    deck.addCard(Card("Diamonds", 7));
    deck.addCard(Card("Hearts", 2));
    deck.addCard(Card("Spades", 11));
    deck.shuffle();
    int playerCount = 0;
    cout << "\nEnter number of players: ";
    cin >> playerCount;
    cin.ignore();
    vector<Player> players;
    for (int i = 0; i < playerCount; i++) {
        cout << "Enter name of player " << i + 1 << ": ";
        string name;
        getline(cin, name);
        players.push_back(Player(name));
    }
    Game game(players, deck, rules);
    game.startGame();
    cout << "\nGame started!" << endl;
    cout << "First player: " << game.getCurrentPlayer().getName() << endl;
    bool gameOver = false;
    while (!gameOver) {
        Player& currentPlayer = game.getCurrentPlayer();
        cout << "\nPlayer turn: " << currentPlayer.getName() << endl;
        cout << "Choose an action:" << endl;
        cout << "  1. Draw a card from deck" << endl;
        cout << "  2. Show hand" << endl;
        cout << "  3. Skip turn" << endl;
        cout << "  0. End game" << endl;
        cout << "Your choice: ";
        int choice = 0;
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1:
            if (!deck.isEmpty()) {
                currentPlayer.drawCard(deck);
                cout << currentPlayer.getName() << " drew a card from the deck." << endl;
            }
            else {
                cout << "The deck is empty. Cannot draw a card." << endl;
            }
            break;
        case 2: {
            vector<Card> hand = currentPlayer.getHand();
            if (hand.empty()) {
                cout << currentPlayer.getName() << ", your hand is empty." << endl;
            }
            else {
                cout << "Cards in " << currentPlayer.getName() << "'s hand:" << endl;
                for (const auto& card : hand) {
                    cout << "  " << card.getType() << " - " << card.getValue() << endl;
                }
            }
            break;
        }
        case 3:
            cout << currentPlayer.getName() << " skips turn." << endl;
            break;
        case 0:
            cout << "\nGame ended by player's decision." << endl;
            gameOver = true;
            continue;
        default:
            cout << "Invalid choice, please try again." << endl;
            continue;
        }
        if (deck.isEmpty()) {
            cout << "\nThe deck is empty. The game is over." << endl;
            gameOver = true;
        }
        else {
            game.nextTurn();
        }
    }
    cout << "\nFinal status of players:" << endl;
    for (const auto& p : players) {
        cout << "Player " << p.getName() << " has " << p.getHandSize() << " cards." << endl;
    }
    cout << "\nPress Enter to exit...";
    cin.get();
    return 0;
}
