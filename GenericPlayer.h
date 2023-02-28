#pragma once

#include "Hand.h"

#include <iostream>
#include <string>

class GenericPlayer : public Hand {
public:
    GenericPlayer(const std::string& name);

    virtual ~GenericPlayer();

    // Indicates whether or not the player wants to hit
    virtual bool IsHitting() const = 0;

    // Returns whether or not the player has busted (i.e. has a hand value greater than 21)
    bool IsBusted() const;

    // Outputs the player's name
    friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& player);

protected:
    std::string m_Name;
};
