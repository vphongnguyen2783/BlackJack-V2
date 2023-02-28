#include "Card.h"

Card::Card(Rank rank, Suit suit, bool isFaceUp) : m_Rank(rank), m_Suit(suit), m_IsFaceUp(isFaceUp) {}

int Card::GetValue() const {
    // If the card is face down, it has no value
    int value = 0;
    if (m_IsFaceUp) {
        // If the card is an ace, its value is 11
        if (m_Rank == RANK_ACE) {
            value = 11;
        }
        // Otherwise, its value is its rank plus 2
        else {
            value = m_Rank + 2;
        }
    }
    return value;
}

void Card::Flip() {
    m_IsFaceUp = !m_IsFaceUp;
}

std::ostream& operator<<(std::ostream& os, const Card& card) {
    const std::vector<std::string> RANK_NAMES = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
    const std::vector<std::string> SUIT_NAMES = {"Clubs", "Diamonds", "Hearts", "Spades"};

    if (card.m_IsFaceUp) {
        os << RANK_NAMES[card.m_Rank] << " of " << SUIT_NAMES[card.m_Suit];
    }
    else {
        os << "Face Down";
    }
    return os;
}
