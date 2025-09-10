#include "Board.hpp"

namespace board {

bool Board::Shoot(const Coordinates& coord) const {
    if (cells_.find(coord) == cells_.end()) return false;
    for (const ShipPtr& ship : ships_) {
        bool hit = ship->IsHit(coord);
        if (hit) return hit;
    }
}

}  // namespace board
