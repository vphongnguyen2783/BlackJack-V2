#pragma once

#include <iostream>
#include <array>
#include <random>
#include <ctime>
#include <algorithm>

#include "Hand.h"

class Deck {
public:
    Deck();

    // Initializes deck with 52 cards
    void Populate();

    // Shuffles deck
    void Shuffle();

    // Removes the top card from the deck and deals it to the hand
    void DealHand(Hand& hand);

    // Removes the top card from the deck and adds it to the hand
    void DealCard(Hand& hand);

private:
    std::array<Card, 52> m_Cards;
    unsigned int m_CurrentCardIndex = 0;

    // Generates random number between min and max (inclusive)
    static int GetRandomNumber(int min, int max);
};
