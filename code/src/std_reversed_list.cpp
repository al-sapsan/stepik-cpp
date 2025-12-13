/**********************************************************************
 * @file script6.cpp
 * @brief Проверка односвязного списка на палиндром.
 *
 * @details Программа считывает N элементов в std::forward_list
 * и определяет, является ли последовательность палиндромом
 * (читается одинаково слева направо и справа налево).
 *
 * @date 2025-01-01
 * @copyright Copyright (c) 2025
 **********************************************************************/

/********** Core **********/
#include <forward_list>
#include <iostream>

/********** Function Definition **********/
/**
 * @brief: Переворачивает односвязный список.
 * @param list: Исходный односвязный список.
 * @return: Перевернутый односвязный список.
 */
std::forward_list<int> reverse_list(std::forward_list<int> list);

/********** Main Function **********/
/**
 * @brief Точка входа программы.
 * @return 0 при успешном выполнении
 */
int main()
{
    int n;
    std::cin >> n;

    std::forward_list<int> numbers;

    if (n == 0)
    {
        std::cout << "YES\n";
        return 0;
    }

    // Чтение списка
    auto it = numbers.before_begin();
    for (int i = 0; i < n; ++i)
    {
        int value;
        std::cin >> value;
        it = numbers.insert_after(it, value);
    }

    // Создаем обратную копию
    std::forward_list<int> reversed = reverse_list(numbers);

    // Сравниваем оригинальный и обратный списки
    bool is_palindrome = true;
    auto it1 = numbers.begin();
    auto it2 = reversed.begin();

    for (int i = 0; i < n; ++i)
    {
        if (*it1 != *it2)
        {
            is_palindrome = false;
            break;
        }
        ++it1;
        ++it2;
    }

    std::cout << (is_palindrome ? "YES" : "NO") << '\n';

    return 0;
}

/********** Function Implementation **********/

std::forward_list<int> reverse_list(std::forward_list<int> list)
{
    std::forward_list<int> reversed;
    for (const auto& num : list)
    {
        reversed.push_front(num);
    }
    return reversed;
}
