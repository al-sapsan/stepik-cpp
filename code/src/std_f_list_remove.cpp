/**********************************************************************
 * @file script7.cpp
 * @brief Удаление всех узлов с заданным значением из односвязного списка.
 *
 * @details Программа считывает N элементов в std::forward_list,
 * затем удаляет все узлы со значением val и выводит обновлённый
 * список или "EMPTY", если список стал пустым.
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

    int val;
    std::cin >> val;

    // Удаляем все элементы со значением val
    numbers.remove(val);

    // Проверяем, пуст ли список после удаления
    if (numbers.empty())
    {
        std::cout << "EMPTY\n";
    }
    else
    {
        // Выводим оставшиеся элементы
        for (const auto& num : numbers)
        {
            std::cout << num << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
