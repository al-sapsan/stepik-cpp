/**********************************************************************
 * @file script3.cpp
 * @brief Вывод элементов массива в обратном порядке с умножением на следующий элемент.
 *
 * @details Программа считывает 5 целых чисел, разделённых пробелом,
 * выводит элементы в обратном порядке, при этом каждый элемент
 * умножается на следующий (завершающий элемент умножается на 1).
 *
 * @date 2024-12-10
 * @copyright Copyright (c) 2024
 **********************************************************************/

#include <array>
#include <iostream>
#include <algorithm> // for std::reverse_copy

int main()
{
    constexpr size_t SIZE = 5;
    std::array<int, SIZE> numbers;
    std::array<int, SIZE> reversed;

    // Read input with validation
    for (auto& num : numbers)
    {
        if (!(std::cin >> num))
        {
            std::cerr << "Error: Invalid input.\n";
            return 1;
        }
    }

    // Reverse the array
    std::reverse_copy(numbers.begin(), numbers.end(), reversed.begin());

    // Apply multiplication: each element *= next (last *= 1)
    for (size_t i = 0; i < SIZE - 1; ++i)
    {
        reversed[i] *= reversed[i + 1];
    }

    // Output with no trailing space
    for (size_t i = 0; i < SIZE; ++i)
    {
        std::cout << reversed[i];
        if (i != SIZE - 1) std::cout << ' ';
    }
    std::cout << '\n';

    return 0;
}
