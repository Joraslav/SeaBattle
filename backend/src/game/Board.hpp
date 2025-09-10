#pragma once

#include "Coordinates.hpp"
#include "Ship.hpp"

#include <array>
#include <memory>
#include <unordered_map>
#include <vector>

namespace board {

/**
 * @brief Максимально число кораблей на доске
 */
constexpr size_t MAX_SHIPS = 10;

/**
 * @brief Размер колонки доски
 */
constexpr coord::Index COLUMN_SIZE = 10;

/**
 * @brief Класс игровой доски
 */
class Board {
 public:
    using Ship = game::Ship;
    using ShipPtr = std::unique_ptr<Ship>;
    using Coordinates = coord::Coordinates;

    enum class StateCell { UNKNOWN, EMPTY, KILLED, SHIP };

    Board() = default;

    /**
     * @brief Добавляет корабль на доску
     * @param ship Указатель на корабль
     * @param coord Координаты на доске
     */
    void AddShip(ShipPtr ship, const Coordinates& coord);

    /**
     * @brief Выстрел
     * @param coord Координаты выстрела
     * @return StateCell состояние клетки после выстрела
     */
    StateCell Shoot(const Coordinates& coord);

 private:
    // ------ Данные ------
    std::vector<ShipPtr> ships_;
    std::unordered_map<Coordinates, ShipPtr, coord::CoordinatesHash> cells_;
    std::array<StateCell, COLUMN_SIZE * COLUMN_SIZE> cells_state_;

    // ------ Методы ------
    StateCell& Get(const Coordinates& coord);
    const StateCell& Get(const Coordinates& coord) const;
};

}  // namespace board
