#include "Deck.h"

Deck::Deck() {
    Populate();
}

void Deck::Populate() {
    m_CurrentCardIndex = 0;
    for (int suit = Suit::SUIT_CLUBS; suit <= Suit::SUIT_SPADES; ++suit) {
        for (int rank = Rank::RANK_TWO; rank <= Rank::RANK_ACE; ++rank) {
            m_Cards[(suit * 13) + rank] = Card(static_cast<Rank>(rank), static_cast<Suit>(suit));
        }
    }
}


void Deck::Shuffle() {
    m_CurrentCardIndex = 0;
    static std::mt19937 rng(static_cast<unsigned int>(time(nullptr)));
    shuffle(m_Cards.begin(), m_Cards.end(), rng);
}

void Deck::DealHand(Hand& hand) {
    DealCard(hand);
    DealCard(hand);
}

void Deck::DealCard(Hand& hand) {
    hand.AddCard(&m_Cards[m_CurrentCardIndex++]);
}

int Deck::GetRandomNumber(int min, int max) {
    static std::mt19937 rng(static_cast<unsigned int>(time(nullptr)));
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}
