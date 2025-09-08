#pragma once

#include "Coordinates.hpp"

#include <vector>

namespace game {

/**
 * @brief Шаблонный класс корабля
 */
class Ship {
 public:
    using Coordinates = coord::Coordinates;

    Ship(const std::vector<Coordinates>& positions)
        : positions_(positions), hits_(positions.size(), false) {}

    /**
     * @brief Проверка попадания в корабль
     * @param coord Координата выстрела
     * @return true если попадание было, false если нет
     */
    virtual bool IsHit(const Coordinates& coord) noexcept;

    /**
     * @brief Проверка уничтожения корабля
     * @return true если корабль уничтожен, false если нет
     */
    virtual bool IsDestroyed() const noexcept;

    /**
     * @brief Координаты корабля
     * @return Ссылка на координаты корабля
     */
    virtual const std::vector<Coordinates>& GetPositions() const noexcept;

    virtual ~Ship() = default;

 protected:
    std::vector<Coordinates> positions_;
    std::vector<bool> hits_;
};

/**
 * @brief Однопалубный корабль - Катер
 */
class Submarines final : public Ship {
 public:
    Submarines(const Coordinates& pos) : Ship({pos}) {}
    ~Submarines() override = default;

 private:
};

/**
 * @brief Двухпалубный корабль - Эсминец
 */
class Destroyer final : public Ship {
 public:
    Destroyer(const Coordinates& bow, const Coordinates& stern) : Ship({bow, stern}) {}
    ~Destroyer() override = default;

 private:
    /* data */
};

/**
 * @brief Трехпалубный корабль - Крейсер
 */
class Cruiser final : public Ship {
 public:
    Cruiser(const Coordinates& bow, const Coordinates& mid, const Coordinates& stern)
        : Ship({bow, mid, stern}) {}
    ~Cruiser() override = default;

 private:
    /* data */
};

/**
 * @brief Четырехпалубный корабль - Линкор
 */
class Battleship final : public Ship {
 public:
    Battleship(const Coordinates& bow, const Coordinates& mid1, const Coordinates& mid2,
               const Coordinates& stern)
        : Ship({bow, mid1, mid2, stern}) {}
    ~Battleship() override = default;

 private:
    /* data */
};

}  // namespace game
