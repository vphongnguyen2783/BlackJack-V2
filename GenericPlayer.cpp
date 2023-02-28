#include "GenericPlayer.h"

GenericPlayer::GenericPlayer(const std::string& name) : m_Name(name) {}

GenericPlayer::~GenericPlayer() {}

bool GenericPlayer::IsBusted() const {
    return (GetValue() > 21);
}

std::ostream& operator<<(std::ostream& os, const GenericPlayer& player) {
    os << player.m_Name << ":\t";
    for (auto& card : player.m_Cards) {
        os << *card << "\t";
    }
    if (player.GetValue() != 0) {
        os << "(" << player.GetValue() << ")";
    }
    os << std::endl;
    return os;
} 
