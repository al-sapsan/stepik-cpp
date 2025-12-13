/**********************************************************************
 * @file script4.cpp
 * @brief Поиск среднего элемента односвязного списка.
 *
 * @details Программа считывает N элементов в std::forward_list
 * и находит средний элемент. Для нечётного N возвращает единственный
 * средний элемент, для чётного N — второй из двух средних.
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
    std::forward_list<int>::iterator last_it;
    bool first = true;

    // Читаем элементы и добавляем в конец списка
    for (int i = 0; i < n; ++i)
    {
        int value;
        std::cin >> value;

        if (first)
        {
            numbers.push_front(value);
            last_it = numbers.begin();
            first = false;
        }
        else
        {
            last_it = numbers.insert_after(last_it, value);
        }
    }

    // Вычисляем позицию среднего элемента
    int middle_pos = n / 2;

    // Переходим к среднему элементу
    auto it = numbers.begin();
    for (int i = 0; i < middle_pos; ++i)
    {
        ++it;
    }

    // Выводим средний элемент
    std::cout << *it << '\n';

    return 0;
}
