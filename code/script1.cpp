/**********************************************************************
 * @file script1.cpp
 * @brief Удаление первого и последнего элемента массива.
 *
 * @details Программа считывает размер массива n и n целых чисел,
 * затем удаляет первый и последний элемент с помощью std::deque
 * и выводит оставшиеся элементы.
 *
 * @date 2025-01-01
 * @copyright Copyright (c) 2025
 **********************************************************************/

/********** Core **********/
#include <deque>
#include <iostream>

/********** Main Function **********/
/**
 * @brief Точка входа программы.
 *
 * @return 0 при успешном выполнении
 */
int main(void)
{
    int n;
    std::cin >> n;
    if (n <= 0)
        {
            std::cout << std::endl;
            return 0;
        }

    std::deque<int> numbers;
    // Читаем элементы
    for (int i = 0; i < n; ++i)
    {
        int value;
        std::cin >> value;
        numbers.push_back(value);
    }

    // Удаляем, только если есть что удалять
    if (!numbers.empty())
        numbers.pop_front();

    if (!numbers.empty())
        numbers.pop_back();

    // Выводим оставшиеся
    for (size_t i = 0; i < numbers.size(); ++i)
    {
        if (i > 0) std::cout << ' ';
        std::cout << numbers[i];
    }
    std::cout << '\n';

    return 0;
}
