/**********************************************************************
 * @file script2.cpp
 * @brief Подсчёт суммы всех чётных элементов массива.
 *
 * @details Программа считывает 5 целых чисел, разделённых пробелом,
 * и вычисляет сумму всех чётных элементов массива.
 * Использует std::array и современный C++.
 *
 * @date 2024-12-10
 * @copyright Copyright (c) 2024
 **********************************************************************/

#include <array>
#include <iostream>
#include <numeric>

int main()
{
    constexpr size_t SIZE = 5;
    std::array<int, SIZE> numbers{};

    // Read all 5 numbers
    for (auto& num : numbers)
    {
        if (!(std::cin >> num))
        {
            std::cerr << "Error: Invalid input detected.\n";
            return 1;
        }
    }

    // Sum even numbers using std::accumulate
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0,
                              [](int acc, int n) {
                                  return (n % 2 == 0) ? acc + n : acc;
                              });

    std::cout << sum << '\n';
    return 0;
}
