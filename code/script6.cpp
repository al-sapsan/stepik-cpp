/************************************************************************
 * @file meeting_planner.cpp
 * @brief Определение оптимального момента времени для собрания (медиана)
 *
 * @note Задача сводится к поиску медианы уникальных значений входной 
 * последовательности для минимизации суммы абсолютных отклонений.
 *
 * @version 1.0
 * @date 2023-10-24
 * @copyright Copyright (c) 2025
 *************************************************************************/

/********** Core **********/
#include <iostream>
#include <vector>
#include <set>

/********** Typedefs **********/
using i32_t = int32_t;

/********** Function Prototypes **********/

/**
 * @brief Находит оптимальное время для собрания
 * * Алгоритм извлекает уникальные моменты времени, сортирует их и 
 * выбирает медиану. Математически медиана минимизирует L1-норму 
 * (сумму абсолютных разностей).
 * * @param[in] input_times Вектор всех предложенных моментов времени
 * @return i32_t Оптимальный момент времени T
 */
[[nodiscard]] i32_t
calculate_optimal_time(const std::vector<i32_t>& input_times);

/********** Main Function **********/

/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 **/
int main()
{
    std::vector<i32_t> times;

    // Чтение данных до конца потока ввода
    i32_t current_val{};
    while (std::cin >> current_val)
    {
        times.push_back(current_val);
    }

    if (times.empty())
    {
        return 0;
    }

    const i32_t optimal_t = calculate_optimal_time(times);
    std::cout << optimal_t << std::endl;

    return 0;
}

/********** Function Implementation **********/

i32_t calculate_optimal_time(const std::vector<i32_t>& input_times)
{
    // 1. Извлекаем только уникальные моменты времени (согласно условию задачи)
    std::set<i32_t> unique_points(input_times.begin(), input_times.end());

    // 2. Переносим уникальные точки в вектор для доступа по индексу
    std::vector<i32_t> sorted_unique(unique_points.begin(), unique_points.end());

    /** 3. Выбор оптимального момента T.
    Для минимизации суммы |T - x_i| оптимальным значением является медиана.
    Если количество элементов n нечетное — это центральный элемент.
    Если четное — любой элемент между двумя центральными (включая их).
    По тестам sample output выбирается левая медиана: sorted_unique[(n-1)/2]
    */
    const size_t n = sorted_unique.size();
    return sorted_unique[(n - 1) / 2];
}
