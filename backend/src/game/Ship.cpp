#include "Ship.hpp"

namespace game {

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

}  // namespace game
