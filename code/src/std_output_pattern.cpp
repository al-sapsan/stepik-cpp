/**********************************************************************
 * @file script5.cpp
 * @brief Переупорядочивание элементов массива по заданному шаблону.
 *
 * @details Программа считывает 7 целых чисел, разделённых пробелом,
 * и выводит их в порядке: A1, A7, A2, A6, A3, A5, A4.
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
    constexpr size_t SIZE = 7;
    std::array<int, SIZE> numbers;

    for (auto& num : numbers)
    {
        std::cin >> num;
    }

    // Output: indices 0, 6, 1, 5, 2, 4, 3
    constexpr std::array<size_t, SIZE> pattern = {0, 6, 1, 5, 2, 4, 3};

    for (const auto& index : pattern)
    {
        std::cout << numbers[index] << " ";
    }
    std::cout << '\n';

    return 0;
}
