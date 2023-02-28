#include "Player.h"

Player::Player(const std::string& name) : GenericPlayer(name) {}

Player::~Player() {}

bool Player::IsHitting() const {
    char answer;
    std::cout << m_Name << ", do you want to hit? (Y/N): ";
    std::cin >> answer;
    return (answer == 'y' || answer == 'Y');
}

void Player::Win() const {
    std::cout << m_Name << " wins!" << std::endl;
}

void Player::Lose() const {
    std::cout << m_Name << " loses." << std::endl;
}

void Player::Push() const {
    std::cout << m_Name << " pushes." << std::endl;
}
