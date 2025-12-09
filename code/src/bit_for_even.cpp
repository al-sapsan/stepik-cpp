/**********************************************************************
 * @file script2.cpp
 * @brief Подсчёт суммы всех чётных элементов массива.
 *
 * @details Программа считывает 5 целых чисел, разделённых пробелом,
 * и вычисляет сумму всех чётных элементов массива.
 * Использует std::array и современный C++.
 *
 * @date 2025-01-01
 * @copyright Copyright (c) 2025
 **********************************************************************/

/********** Core **********/
#include <array>
#include <iostream>

/********** Main Function **********/
/**
 * @brief Точка входа программы.
 *
 * @return 0 при успешном выполнении
 */
int main(void)
{
    constexpr size_t SIZE = 5;
    std::array<int, SIZE> numbers;

    for (auto& num : numbers)
    {
        std::cin >> num;
    }

    /* Calculate sum of even elements */
    int sum = 0;
    for (const auto& num : numbers)
    {
    /** Используем битовую операцию для проверки четности
    (num & 1) == 0 означает, что младший бит равен 0 → число четное */
        if ((num & 1) == 0)
        {
            sum += num;
        }
    }
    std::cout << sum << std::endl;
    return 0;
}
