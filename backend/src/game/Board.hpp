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

    Board(/* args */);
    ~Board();

 private:
    /* data */
};

}  // namespace board
