#include <iostream>
#include <string>
#include <vector>

#include "Game.h"

int main() {
    std::cout << "Welcome to Blackjack!\n\n";

    int numPlayers = 0;
    while (numPlayers < 1 || numPlayers > 7) {
        std::cout << "How many players? (1 - 7): ";
        std::cin >> numPlayers;
    }

    std::vector<std::string> names;
    std::string name;
    for (int i = 0; i < numPlayers; ++i) {
        std::cout << "Enter player name: ";
        std::cin >> name;
        names.push_back(name);
    }
    std::cout << '\n';

    // Play the game
    Game game(names);
    char again = 'y';
    while (again != 'n' && again != 'N') {
        game.Play();
        std::cout << "\nDo you want to play again? (Y/N): ";
        std::cin >> again;
    }

    return 0;
}
