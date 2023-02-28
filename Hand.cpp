#include "Hand.h"

Hand::Hand() {}

Hand::~Hand() {
    Clear();
}

void Hand::AddCard(Card* pCard) {
    m_Cards.push_back(pCard);
}

void Hand::Clear() {
    // Iterate over the vector of cards, deleting each card and then clearing the vector
    for (auto& card : m_Cards) {
        card = nullptr;
    }
    m_Cards.clear();
}

int Hand::GetValue() const {
    // If the hand has no cards, its value is 0
    if (m_Cards.empty()) {
        return 0;
    }

    // Otherwise, sum up the value of all the cards in the hand
    int value = 0;
    bool hasAce = false;
    for (auto& card : m_Cards) {
        value += card->GetValue();
        if (card->GetValue() == 11) {
            hasAce = true;
        }
    }

    // If the hand has an ace and its value is greater than 21, change the value of the ace to 1
    if (hasAce && value > 21) {
        value -= 10;
    }

    return value;
}
