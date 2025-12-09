/**********************************************************************
 * @file script1.cpp
 * @brief Поиск максимального элемента из 5 целых чисел.
 *
 * @details Программа считывает 5 целых чисел, разделённых пробелом,
 * и находит максимальный элемент без использования встроенных
 * алгоритмов.
 *
 * @date 2025-01-01
 * @copyright Copyright (c) 2025
 **********************************************************************/

/********** Core **********/
#include <iostream>

/********** Main Function **********/
/**
 * @brief Точка входа программы.
 *
 * @return 0 при успешном выполнении
 */
int main(void)
{
    const int SIZE = 5;
    int numbers[SIZE];

    for (int i = 0; i < SIZE; ++i)
    {
        std::cin >> numbers[i];
    }

    /* Find maximum element */
    int max = numbers[0];
    for (int i = 1; i < SIZE; ++i)
    {
        if (numbers[i] > max)
        {
            max = numbers[i];
        }
    }

    std::cout << max << '\n';

    return 0;
}
