#include "Game.h"

Game::Game(const std::vector<std::string>& names) {
    // Create the players
    for (auto& name : names) {
        m_Players.push_back(Player(name));
    }

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Shuffle the deck
    m_Deck.Populate();
    m_Deck.Shuffle();
}

Game::~Game() {}

void Game::Play() {
    // Deal two cards to each player and to the house
    for (int i = 0; i < 2; ++i) {
        for (auto& player : m_Players) {
            m_Deck.DealCard(player);
        }
        m_Deck.DealCard(m_House);
    }

    // Hide the house's first card
    m_House.FlipFirstCard();

    // Display everyone's hand
    for (auto& player : m_Players) {
        std::cout << player;
    }
    std::cout << m_House;

    // Give each player a chance to hit
    for (auto& player : m_Players) {
        while (player.IsHitting()) {
            m_Deck.DealCard(player);
            std::cout << player;
            if (player.IsBusted()) {
                player.Lose();
                break;
            }
        }
    }

    // Reveal the house's first card
    m_House.FlipFirstCard();
    std::cout << m_House;

    // Give the house a chance to hit
    while (m_House.IsHitting()) {
        m_Deck.DealCard(m_House);
        std::cout << m_House;
        if (m_House.IsBusted()) {
            for (auto& player : m_Players) {
                if (!player.IsBusted()) {
                    player.Win();
                }
            }
            return;
        }
    }

    // Determine the winner(s)
    int houseValue = m_House.GetValue();
    for (auto& player : m_Players) {
        if (!player.IsBusted()) {
            int playerValue = player.GetValue();
            if (playerValue > houseValue) {
                player.Win();
            } else if (playerValue < houseValue) {
                player.Lose();
            } else {
                player.Push();
            }
        }
    }

    // Display the results
    for (auto& player : m_Players) {
        player.Clear();
    }
    m_House.Clear();
}
