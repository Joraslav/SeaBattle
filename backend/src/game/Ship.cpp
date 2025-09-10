#include "Ship.hpp"

namespace game {

// ------ Реализация методов класса Ship ------

bool Ship::IsHit(const Coordinates& coord) noexcept {
    for (size_t i = 0; i != positions_.size(); ++i) {
        if (coord == positions_[i]) {
            hits_[i] = true;
            return true;
        }
    }
    return false;
}

bool Ship::IsDestroyed() const noexcept {
    for (bool hit : hits_) {
        if (!hit) {
            return false;
        }
    }

    return true;
}

const std::vector<Ship::Coordinates>& Ship::GetPositions() const noexcept {
    return positions_;
}

// ------ Реализация методов класса Submarines ------

Submarines::Submarines() { hits_.resize(1, false); }

// ------ Реализация методов класса Destroyer ------

Destroyer::Destroyer() { hits_.resize(2, false); }

// ------ Реализация методов класса Cruiser ------

Cruiser::Cruiser() { hits_.resize(3, false); }

// ------ Реализация методов класса Battleship ------

Battleship::Battleship() { hits_.resize(4, false); }

}  // namespace game
