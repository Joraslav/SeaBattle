#include "Board.hpp"

namespace board {

// ------ Public методы ------


Board::StateCell Board::Shoot(const Coordinates& coord) {
    StateCell& cell_state = Get(coord);

}

// ------ Private методы ------

Board::StateCell& Board::Get(const Coordinates& coord) {
    return cells_state_[coord.GetX() + coord.GetY() * COLUMN_SIZE];
}

const Board::StateCell& Board::Get(const Coordinates& coord) const {
    return cells_state_[coord.GetX() + coord.GetY() * COLUMN_SIZE];
}

}  // namespace board
