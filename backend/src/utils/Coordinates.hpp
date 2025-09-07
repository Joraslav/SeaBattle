#pragma once

#include <concepts>
#include <limits>
#include <stdexcept>

namespace coord {

/**
 * @brief Алиас для индекса координат
 */
using Index = unsigned short;

/**
 * @brief Концепт для проверки, что тип можно привести к Index
 * @tparam T тип, который проверяется
 */
template <typename T>
concept ConvertibleToIndex = std::convertible_to<T, Index> && requires(T value) {
    { value <= std::numeric_limits<Index>::max() } -> std::convertible_to<bool>;
};

/**
 * @brief Координаты на игровом поле
 */
class Coordinates {
 public:
    Coordinates() = default;

    template <ConvertibleToIndex T>
    Coordinates(T x, T y) {
        if (x > static_cast<Index>(10) || y > static_cast<Index>(10)) {
            throw std::out_of_range("Coordinates more then 10");
        }

        x_ = static_cast<Index>(x);
        y_ = static_cast<Index>(y);
    }

    Index GetX() const { return x_; }
    Index GetY() const { return y_; }

    bool operator==(const Coordinates& other) const {
        return x_ == other.x_ && y_ == other.y_;
    }

 private:
    Index x_ = 0;
    Index y_ = 0;
};

/**
 * @brief Характеризует расположение коробля на игровом поле
 */
struct Location {
    Coordinates begin;
    Coordinates end;

    Location() = default;
    Location(Coordinates beg, Coordinates en) : begin(beg), end(en) {}
};

}  // namespace coord
