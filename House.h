#pragma once

#include "GenericPlayer.h"

class House : public GenericPlayer {
public:
    House(const std::string& name = "House");

    virtual ~House();

    // Indicates whether or not the house wants to hit
    virtual bool IsHitting() const;

    // Flips over the first card (i.e. reveals the first card)
    void FlipFirstCard();
};
