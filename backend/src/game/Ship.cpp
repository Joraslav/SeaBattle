#include "Ship.hpp"

namespace game {

bool Ship::IsHit(const Coordinates& coord) noexcept {}

bool Ship::IsDestroyed() const noexcept {}

const std::vector<Ship::Coordinates>& Ship::GetPositions() const noexcept {
    return positions_;
}

}  // namespace game
