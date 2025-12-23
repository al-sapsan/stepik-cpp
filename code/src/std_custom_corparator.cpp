/************************************************************************
 * @file script2.cpp
 * @brief Программа для сортировки археологических находок
 *
 * @version 1.0 (C++20)
 * @date 
 * @copyright Copyright (c) 2025 Oleg Sokolov
 *************************************************************************/

/********** Core **********/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

/********** Typedefs **********/
using i64_t = int64_t;
using f64_t = double;

/********** Structure Definition ***********/

/**
 * @brief Структура, представляющая точку интереса на карте
 */
struct Point
{
    i64_t x;     ///< Координата X
    i64_t y;     ///< Координата Y
    i64_t value; ///< Ценность артефакта

    /**
     * @brief Вычисляет квадрат расстояния до начала координат (0,0)
     * @return Квадрат расстояния (используется для сравнения без извлечения корня)
     */
    [[nodiscard]] constexpr i64_t get_distance_sq() const noexcept
    {
        return x * x + y * y;
    }

    /**
     * @brief Кастомный оператор сравнения для сортировки
     * @param other Другая точка для сравнения
     * @return true, если текущая точка должна идти раньше
     */
    bool operator<(const Point& other) const noexcept
    {
        const auto d1 = get_distance_sq();
        const auto d2 = other.get_distance_sq();

        if (d1 != d2)
        {
            return d1 < d2; // Сначала по расстоянию (возрастание)
        }
        return value > other.value; // При равенстве — по ценности (убывание)
    }
};

/********** Main Function **********/
/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 */
int main()
{
    // Оптимизация ввода-вывода
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr); // Use nullptr instead of NULL

    size_t n;
    if (!(std::cin >> n))
        return 0;

    /********** Data Collection **********/
    std::vector<Point> points;
    points.reserve(n);

    for (size_t i = 0; i < n; ++i)
    {
        i64_t x, y, val;
        if (!(std::cin >> x >> y >> val))
            return 0;
        points.emplace_back(Point{ x, y, val }); // Explicit constructor call
    }

    /********** Sorting **********/
    std::sort(points.begin(), points.end());

    /********** Output **********/
    for (const auto& p : points) // Simplified structured binding
    {
        std::cout << p.x << " " << p.y << " " << p.value << "\n";
    }

    return 0;
}
