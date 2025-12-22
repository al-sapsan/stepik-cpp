/************************************************************************
 * @file sequence_stats.cpp
 * @brief Программа для подсчета статистики уникальных чисел в последовательности
 * @note Использует std::map для автоматической сортировки и хранения частот.
 * 
 * @version 1.1
 * @date 2023-10-27
 * @copyright Copyright (c) 2025
 *************************************************************************/

/********** Core **********/
#include <iostream>
#include <sstream>
#include <string>
#include <cstdint>

/********** Containers **********/
#include <map>

/********** Typedefs **********/
using i64 = int64_t;

/********** Data types **********/
/**
 * @brief Структура для хранения статистики вхождения числа
 */
struct NumberStats
{
    size_t count{ 0 }; // Количество вхождений
    i64 sum{ 0 };      // Сумма всех вхождений
};

/********** Function Prototypes **********/

/**
 * @brief Обработка входной строки и расчет статистики
 * @param[in] input Строка с целыми числами
 * @return std::map<int, NumberStats> Отсортированный словарь со статистикой
 */
[[nodiscard]] std::map<int, NumberStats>
calculate_sequence_statistics(const std::string& input);

/**
 * @brief Вывод накопленной статистики в стандартный поток
 * @param[in] stats Словарь со статистикой
 */
void print_statistics(const std::map<int, NumberStats>& stats);

/********** Main Function **********/

/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 */
int main()
{
    std::string line;
    if (std::getline(std::cin, line) && !line.empty())
    {
        const auto stats = calculate_sequence_statistics(line);
        print_statistics(stats);
    }

    return 0;
}

/********** Function Implementation **********/

[[nodiscard]] std::map<int, NumberStats>
calculate_sequence_statistics(const std::string& input)
{
    std::map<int, NumberStats> stats_map;
    std::stringstream ss(input);
    int number;

    // Читаем числа из потока до конца строки
    while (ss >> number)
    {
        auto& entry = stats_map[number];
        entry.count++;
        entry.sum += static_cast<i64>(number);
    }

    return stats_map;
}

void print_statistics(const std::map<int, NumberStats>& stats)
{
    // Используем structured bindings (C++17/20) для итерации по map
    for (const auto& [val, data] : stats)
    {
        std::cout << val << " " << data.count << " " << data.sum << "\n";
    }
}
