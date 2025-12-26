/************************************************************************
 * @file script7.cpp
 * @brief Алгоритм заливки одноцветной области (Flood Fill)
 * @note Используется итеративный подход с очередью (BFS) для обеспечения 
 * стабильности при больших размерах матриц (защита от Stack Overflow).
 *
 * @version 1.0 (C++20)
 * @date 
 * @copyright Copyright (c) 2025 Oleg Sokolov. All rights reserved
 *************************************************************************/

/********** Core **********/
#include <iostream>
#include <vector>
#include <queue>
#include <cstdint>

/********** Typedefs **********/
using i32_t = int32_t;
using matrix_t = std::vector<std::vector<i32_t>>;

/************ Structure Definition ***********/

/**
 * @brief Структура для представления координат пикселя
 */
struct Point
{
    i32_t x{}; // Столбец
    i32_t y{}; // Строка

    /**
     * @brief Оператор сравнения (C++20 default comparison)
     */
    auto operator<=>(const Point&) const = default;
};

/********** Constants **********/
constexpr i32_t REPLACEMENT_COLOR = 2;

/********** Function Prototypes **********/

/**
 * @brief Выполняет перекраску связной области
 * * Алгоритм находит все смежные пиксели того же цвета, что и в стартовой точке, 
 * и заменяет их на REPLACEMENT_COLOR.
 * * @param[in,out] matrix Матрица изображения
 * @param[in] start_pos Координаты начального пикселя
 * @param[in] target_color Исходный цвет области
 * @param[in] new_color Цвет для заливки
 */
void flood_fill(matrix_t& matrix, Point start_pos, i32_t target_color, i32_t new_color);

/********** Main Function **********/

/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 **/
int main()
{
    size_t n{};
    if (!(std::cin >> n))
        return 0;

    Point start_pos{};
    std::cin >> start_pos.x >> start_pos.y;

    // Инициализация матрицы n x n
    matrix_t image(n, std::vector<i32_t>(n));

    // Чтение матрицы
    for (size_t row = 0; row < n; ++row)
    {
        for (size_t col = 0; col < n; ++col)
        {
            std::cin >> image[row][col];
        }
    }

    // Проверка границ и необходимости заливки
    if (start_pos.y >= 0 && static_cast<size_t>(start_pos.y) < n &&
        start_pos.x >= 0 && static_cast<size_t>(start_pos.x) < n)
    {
        const i32_t original_color = image[start_pos.y][start_pos.x];

        if (original_color != REPLACEMENT_COLOR)
        {
            flood_fill(image, start_pos, original_color, REPLACEMENT_COLOR);
        }
    }

    // Вывод результирующей матрицы
    for (size_t row = 0; row < n; ++row)
    {
        for (size_t col = 0; col < n; ++col)
        {
            std::cout << image[row][col] << (col == n - 1 ? "" : " ");
        }
        std::cout << "\n";
    }

    return 0;
}

/********** Function Implementation **********/

/**
 * @brief Реализация алгоритма поиска в ширину (BFS) для заливки
 */
void flood_fill(matrix_t& matrix, Point start_pos, i32_t target_color, i32_t new_color)
{
    const i32_t rows = static_cast<i32_t>(matrix.size());
    if (rows == 0)
        return;
    const i32_t cols = static_cast<i32_t>(matrix[0].size());

    std::queue<Point> pixel_queue;

    // Начальная точка
    matrix[start_pos.y][start_pos.x] = new_color;
    pixel_queue.push(start_pos);

    // Направления смещения (4-связность)
    const std::vector<Point> directions = {
        { 0, 1 },  // вправо
        { 0, -1 }, // влево
        { 1, 0 },  // вниз
        { -1, 0 }  // вверх
    };

    while (!pixel_queue.empty())
    {
        const Point current = pixel_queue.front();
        pixel_queue.pop();

        for (const auto& dir : directions)
        {
            const Point neighbor{ current.x + dir.x, current.y + dir.y };

            // Проверка границ и соответствия цвета
            if (neighbor.y >= 0 && neighbor.y < rows &&
                neighbor.x >= 0 && neighbor.x < cols &&
                matrix[neighbor.y][neighbor.x] == target_color)
            {
                matrix[neighbor.y][neighbor.x] = new_color;
                pixel_queue.push(neighbor);
            }
        }
    }
}
