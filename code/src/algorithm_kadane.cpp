/**********************************************************************
 * @file script8.cpp
 * @brief Нахождение максимальной суммы непрерывного подмассива.
 *
 * @details Программа считывает массив целых чисел и находит
 * максимальную сумму непрерывного подмассива, используя
 * алгоритм Кадане (Kadane's Algorithm).
 *
 * @date 2025-01-01
 * @copyright Copyright (c) 2025
 **********************************************************************/

/********** Core **********/
#include <algorithm>
#include <iostream>
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

    // Читаем все числа из входной строки
    while (std::cin >> value)
    {
        arr.push_back(value);
    }

    // Проверка на пустой массив
    if (arr.empty())
    {
        return 0;
    }

    // Алгоритм Кадане для нахождения максимальной суммы подмассива
    int max_current = arr[0];
    int max_global = arr[0];

    for (size_t i = 1; i < arr.size(); ++i)
    {
        // Выбираем: начать новый подмассив с текущего элемента
        // или продолжить существующий
        max_current = std::max(arr[i], max_current + arr[i]);

        // Обновляем глобальный максимум
        max_global = std::max(max_global, max_current);
    }

    std::cout << max_global << '\n';

    return 0;
}
