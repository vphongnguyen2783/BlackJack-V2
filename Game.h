#pragma once

#include <ctime>

#include "Deck.h"
#include "House.h"
#include "Player.h"

class Game {
public:
    Game(const std::vector<std::string>& names);

    ~Game();

    // Plays the game of blackjack
    void Play();

private:
    Deck m_Deck;
    House m_House;
    std::vector<Player> m_Players;
};
