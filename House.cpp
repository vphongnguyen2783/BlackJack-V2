#include "House.h"

House::House(const std::string& name) : GenericPlayer(name) {}

House::~House() {}

bool House::IsHitting() const {
    return (GetValue() <= 16);
}

void House::FlipFirstCard() {
    if (!m_Cards.empty()) {
        m_Cards.front()->Flip();
    }
}
