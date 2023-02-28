#pragma once

#include "GenericPlayer.h"

class Player : public GenericPlayer {
public:
    Player(const std::string& name);

    virtual ~Player();

    // Returns whether or not the player wants to hit
    virtual bool IsHitting() const;

    // Announces that the player wins
    void Win() const;

    // Announces that the player loses
    void Lose() const;

    // Announces that the player pushes (i.e. ties with the dealer)
    void Push() const;
};