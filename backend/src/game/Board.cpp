#include "Board.hpp"

namespace board {

// ------ Public методы ------

// Один из вариантов реализации
/*
void Board::AddShip(ShipPtr ship, const Coordinates& coord) {
    // Проверка на максимальное количество кораблей
    if (ships_.size() >= MAX_SHIPS) return;

    // Проверка на пересечение с существующими кораблями
    const auto& new_positions = ship->GetPositions();
    for (const auto& s : ships_) {
        for (const auto& pos : s->GetPositions()) {
            for (const auto& new_pos : new_positions) {
                if (pos == new_pos) return; // Пересечение, не добавляем
            }
        }
    }

    // Добавляем корабль
    ships_.push_back(std::move(ship));

    // Обновляем состояние клеток
    for (const auto& pos : new_positions) {
        Get(pos) = StateCell::SHIP;
    }
}
*/

//
Board::StateCell Board::Shoot(const Coordinates& coord) {
    // Заглушка
    return StateCell::EMPTY;
}

// ------ Private методы ------

Board::StateCell& Board::Get(const Coordinates& coord) {
    return cells_state_[coord.GetX() + coord.GetY() * COLUMN_SIZE];
}

const Board::StateCell& Board::Get(const Coordinates& coord) const {
    return cells_state_[coord.GetX() + coord.GetY() * COLUMN_SIZE];
}

}  // namespace board
