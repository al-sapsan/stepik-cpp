/**********************************************************************
 * @file script1.cpp
 * @brief Удаление чётных чисел из вектора.
 *
 * @details Программа считывает последовательность целых чисел,
 * удаляет из неё все чётные числа и выводит результат.
 *
 * @date 2025-01-01
 * @copyright Copyright (c) 2025
 **********************************************************************/

/********** Core **********/
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
    std::vector<int> numbers;
    int num;

    /* Read all numbers from input */
    while (std::cin >> num)
    {
        numbers.push_back(num);
    }

    /* Remove even numbers using erase-remove idiom */
    auto it = numbers.begin();
    while (it != numbers.end())
    {
        if (*it % 2 == 0)
        {
            it = numbers.erase(it);
        }
        else
        {
            ++it;
        }
    }

    /* Output remaining odd numbers */
    for (const auto& n : numbers)
    {
        std::cout << n << " ";
    }

    if (!numbers.empty())
    {
        std::cout << std::endl;
    }

    return 0;
}
