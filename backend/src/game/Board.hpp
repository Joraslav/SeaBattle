#pragma once

#include "Coordinates.hpp"
#include "Ship.hpp"

#include <memory>
#include <unordered_map>
#include <vector>

namespace board {

/**
 * @brief Максимально число кораблей на доске
 */
constexpr size_t MAX_SHIPS = 10;

/**
 * @brief Класс игровой доски
 */
class Board {
 public:
    using Ship = game::Ship;
    using ShipPtr = std::unique_ptr<Ship>;
    using Coordinates = coord::Coordinates;

    Board() = default;

    /**
     * @brief Добавляет корабль на доску
     * @param ship Указатель на корабль
     * @param coord Координаты на доске
     * @return true если корабль добавлен, false если нет
     */
    bool AddShip(ShipPtr ship, const Coordinates& coord);

    /**
     * @brief Выстрел
     * @param coord Координаты выстрела
     * @return true если попадание в корабль, false если нет
     */
    bool Shoot(const Coordinates& coord) const;

 private:
    std::vector<ShipPtr> ships_;
    std::unordered_map<Coordinates, Ship*, coord::CoordinatesHash> cells_;
};

}  // namespace board
