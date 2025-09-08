#include "Ship.hpp"

namespace game {

/**
 * @4monika Реализация
 */
bool Ship::IsHit(const Coordinates& coord) noexcept {
    for (size_t i = 1; i < positions_.size(); i++) {
        if (coord == positions_[i]) {
            hits_[i] = true;
            return true;
        }
    }
    return false;
}

/**
 * @4monika Реализация
 */
bool Ship::IsDestroyed() const noexcept {
    for (size_t i = 1; i < hits_.size(); i++) {
        if (!hits_[i]) {
            return false;
        }
    }
    return true;
}
/**
 * @4monika Реализация
 */
const std::vector<Ship::Coordinates>& Ship::GetPositions() const noexcept {
    return positions_;
}

}  // namespace game
