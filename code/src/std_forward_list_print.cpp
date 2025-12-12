/**********************************************************************
 * @file script2.cpp
 * @brief Вывод массива в обратном порядке.
 *
 * @details Программа считывает размер массива n и n целых чисел,
 * затем выводит элементы в обратном порядке через пробел.
 * Использует std::forward_list для хранения данных.
 *
 * @date 2025-01-01
 * @copyright Copyright (c) 2025
 **********************************************************************/

/********** Core **********/
#include <forward_list>
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

    std::forward_list<int> numbers;

    // Читаем элементы и добавляем в начало списка
    // Таким образом, они автоматически окажутся в обратном порядке
    for (int i = 0; i < n; ++i)
    {
        int value;
        std::cin >> value;
        numbers.push_front(value);
    }

    // Выводим элементы (они уже в обратном порядке)
    bool first = true;
    for (const auto& num : numbers)
    {
        if (!first)
        {
            std::cout << ' ';
        }
        std::cout << num;
        first = false;
    }
    std::cout << '\n';

    return 0;
}
