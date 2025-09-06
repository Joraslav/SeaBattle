#pragma once

namespace game {

/**
 * @brief Шаблонный класс корабля
 * @tparam T тип корабля
 */
class Ship {
 public:
    Ship(/* args */);
    virtual ~Ship() = 0;
};

/**
 * @brief Однопалубный корабль - Катер
 */
class Submarines : public Ship {
 public:
    Submarines(/* args */);
    ~Submarines();

 private:
    /* data */
};

/**
 * @brief Двухпалубный корабль - Эсминец
 */
class Destroyer : public Ship {
 public:
    Destroyer(/* args */);
    ~Destroyer();

 private:
    /* data */
};

/**
 * @brief Трехпалубный корабль - Крейсер
 */
class Cruiser : public Ship {
 public:
    Cruiser(/* args */);
    ~Cruiser();

 private:
    /* data */
};

/**
 * @brief Четырехпалубный корабль - Линкор
 */
class Battleship : public Ship {
 public:
    Battleship(/* args */);
    ~Battleship();

 private:
    /* data */
};

}  // namespace game
