/**********************************************************************
 * @file script2.cpp
 * @brief Вычисление "счёта" строки — сумма абсолютных разностей ASCII соседних символов.
 *
 * @details Считывает одну строку `s` (включая пробелы) и вычисляет сумму
 * |s[i] - s[i-1]| для всех соседних пар символов. Выводит целое число — сумму.
 *
 * @date 2025-12-01
 * @copyright Copyright (c) 2025
 **********************************************************************/

/********** Core **********/
#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <cstdlib>
#include <algorithm>

/********** Main Function **********/
/**
 * @brief Точка входа программы.
 *
 * @return 0 при успешном выполнении
 */
int main()
{
    std::string s;

    if (!std::getline(std::cin, s))
    {
        std::cout << "0\n";
        return 0;
    }

    // Удаляем символы новой строки и возврата каретки
    s.erase(std::remove(s.begin(), s.end(), '\n'), s.end());
    s.erase(std::remove(s.begin(), s.end(), '\r'), s.end());

    // Вычисляем сумму с помощью std::accumulate
    long long sum = 0;
    if (s.size() > 1)
    {
        for (size_t i = 1; i < s.size(); ++i)
        {
            sum += std::abs(static_cast<int>(s[i]) - static_cast<int>(s[i - 1]));
        }
    }

    std::cout << sum << "\n";
    return 0;
}