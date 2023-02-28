#pragma once

#include "Card.h"

#include <vector>

class Hand {
public:
    Hand();

    virtual ~Hand();

    // Adds a card to the hand
    void AddCard(Card* pCard);

    // Clears the hand of all cards
    void Clear();

    // Gets the total value of the hand
    int GetValue() const;

protected:
    std::vector<Card*> m_Cards;
};
