#include "Ship.hpp"

namespace game {

using namespace coord;

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

void Ship::SetPositions(const std::vector<Coordinates>& positions) {
    positions_ = positions;
    direction_ = {positions_.front(), positions_.back()};
}

std::vector<Coordinates> Ship::Rotate() const {
    const Index move_param = hits_.size() - 1;
    bool is_horizontal = direction_.begin.GetY() == direction_.end.GetY();
    std::vector<Coordinates> new_positions;
    if (is_horizontal) {
        const Index x_end_candidate = direction_.end.GetX();
        const Index y_end_candidate = direction_.end.GetY() + move_param;

        const Index y_end = (y_end_candidate < MAX_INDEX)
                                ? y_end_candidate
                                : direction_.end.GetY() - move_param;
        const Index x_end = (x_end_candidate < direction_.begin.GetX())
                                ? x_end_candidate + move_param
                                : x_end_candidate - move_param;

        new_positions.push_back(direction_.begin);
        new_positions.emplace_back(x_end, y_end);

    } else {
        const Index x_end_candidate = direction_.end.GetX() + move_param;
        const Index y_end_candidate = direction_.end.GetY();

        const Index x_end = (x_end_candidate < MAX_INDEX)
                                ? x_end_candidate
                                : direction_.end.GetX() - move_param;
        const Index y_end = (y_end_candidate < direction_.begin.GetY())
                                ? y_end_candidate - move_param
                                : y_end_candidate + move_param;

        new_positions.push_back(direction_.begin);
        new_positions.emplace_back(x_end, y_end);
    }

    return new_positions;
}

const std::vector<Ship::Coordinates>& Ship::GetPositions() const { return positions_; }

// ------ Реализация методов класса Submarines ------

Submarines::Submarines() { hits_.resize(1, false); }

// ------ Реализация методов класса Destroyer ------

Destroyer::Destroyer() { hits_.resize(2, false); }

// ------ Реализация методов класса Cruiser ------

Cruiser::Cruiser() { hits_.resize(3, false); }

// ------ Реализация методов класса Battleship ------

Battleship::Battleship() { hits_.resize(4, false); }

}  // namespace game
