#pragma once

#include <iostream>
#include <string>
#include <vector>

enum Rank {
    RANK_TWO,
    RANK_THREE,
    RANK_FOUR,
    RANK_FIVE,
    RANK_SIX,
    RANK_SEVEN,
    RANK_EIGHT,
    RANK_NINE,
    RANK_TEN,
    RANK_JACK,
    RANK_QUEEN,
    RANK_KING,
    RANK_ACE
};

enum Suit {
    SUIT_CLUBS,
    SUIT_DIAMONDS,
    SUIT_HEARTS,
    SUIT_SPADES
};

class Card {
public:
    Card(Rank rank = RANK_TWO, Suit suit = SUIT_CLUBS, bool isFaceUp = true);

    // Returns the numerical value of the card
    int GetValue() const;

    // Flips the card - if face up, becomes face down and vice versa
    void Flip();

    // Outputs the name of the card (e.g. "Two of Clubs")
    friend std::ostream& operator<<(std::ostream& os, const Card& card);

private:
    Rank m_Rank;
    Suit m_Suit;
    bool m_IsFaceUp;
};