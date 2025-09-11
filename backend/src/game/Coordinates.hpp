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

// ------ Константы ------

constexpr Index MAX_INDEX = 10;

/**
 * @brief Координаты на игровом поле
 */
class Coordinates {
 public:
    Coordinates() = default;
    Coordinates(const Coordinates& other) = default;
    Coordinates& operator=(const Coordinates& rhs) = default;
    Coordinates(Coordinates&& other) noexcept = default;
    Coordinates& operator=(Coordinates&& rhs) noexcept = default;

    template <ConvertibleToIndex T>
    Coordinates(T x, T y) {
        if (x > MAX_INDEX || y > MAX_INDEX) {
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

struct CoordinatesHash {
    std::size_t operator()(const coord::Coordinates& coord) const noexcept {
        // Более сложное смешивание с использованием константы и побитовых операций
        std::size_t x_hash = std::hash<Index>()(coord.GetX());
        std::size_t y_hash = std::hash<Index>()(coord.GetY());
        // Используем магическое число и смешивание битов
        return (x_hash * 0x9e3779b9) ^
               (y_hash + 0x9e3779b9 + (x_hash << 6) + (x_hash >> 2));
    }
};

/**
 * @brief Характеризует расположение коробля на игровом поле
 * @param beg начальная координата
 * @param end конечная координата
 */
struct Direction {
    Coordinates begin;
    Coordinates end;

    Direction(Coordinates beg, Coordinates en) : begin(beg), end(en) {}
};

}  // namespace coord
