/**********************************************************************
 * @file script9.cpp
 * @brief Нахождение минимальной разности в подмассиве длины K.
 *
 * @details Программа считывает массив целых чисел и число K,
 * затем находит минимальную разность между максимальным и минимальным
 * элементами среди всех подмассивов длины K.
 *
 * @date 2025-01-01
 * @copyright Copyright (c) 2025
 **********************************************************************/

/********** Core **********/
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

/********** Main Function **********/
/**
 * @brief Точка входа программы.
 *
 * @return 0 при успешном выполнении
 */
int main(void)
{
    std::vector<int> arr;
    int value;

    // Читаем все числа из первой строки
    while (std::cin >> value)
    {
        arr.push_back(value);
        if (std::cin.peek() == '\n')
        {
            break;
        }
    }

    int k;
    std::cin >> k;

    // Проверка корректности входных данных
    if (arr.empty() || k <= 0 || k > static_cast<int>(arr.size()))
    {
        return 0;
    }

    int min_difference = std::numeric_limits<int>::max();

    // Перебираем все подмассивы длины k
    for (size_t i = 0; i <= arr.size() - k; ++i)
    {
        // Находим максимум и минимум в текущем подмассиве
        int max_val = arr[i];
        int min_val = arr[i];

        for (int j = 1; j < k; ++j)
        {
            max_val = std::max(max_val, arr[i + j]);
            min_val = std::min(min_val, arr[i + j]);
        }

        // Вычисляем разность и обновляем минимум
        int difference = max_val - min_val;
        min_difference = std::min(min_difference, difference);
    }

    std::cout << min_difference << '\n';

    return 0;
}
