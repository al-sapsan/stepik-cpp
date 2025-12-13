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
#include <stack>

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

    // Используем стек для проверки палиндрома
    std::stack<int> stack;

    // Помещаем первую половину элементов в стек
    auto current = numbers.begin();
    for (int i = 0; i < n / 2; ++i)
    {
        stack.push(*current);
        ++current;
    }

    // Если нечетное количество элементов, пропускаем средний
    if (n % 2 == 1)
    {
        ++current;
    }

    // Сравниваем вторую половину с элементами из стека
    bool is_palindrome = true;
    while (current != numbers.end() && !stack.empty())
    {
        if (*current != stack.top())
        {
            is_palindrome = false;
            break;
        }
        ++current;
        stack.pop();
    }

    std::cout << (is_palindrome ? "YES" : "NO") << '\n';

    return 0;
}
