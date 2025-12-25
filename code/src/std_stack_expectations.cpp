/************************************************************************
 * @file script2.cpp
 * @brief Проверка корректности скобочной последовательности (LeetCode style)
 * @warning Работает только с символами '(', ')', '{', '}', '[', ']'.
 *
 * @version 1.0
 * @date 2025-12-25
 * @copyright Copyright (c) 2025 Oleg Sokolov. All rights reserved
 *************************************************************************/

/********** Core **********/
#include <iostream>
#include <stack>
#include <string>
#include <string_view>

/********** Function Prototypes **********/

/**
 * @brief Проверяет, является ли строка корректной скобочной последовательностью
 * * @param[in] s Входная строка для анализа
 * @return true Если последовательность верна
 * @return false Если есть ошибки в типах или порядке скобок
 */

[[nodiscard]] bool
is_valid_sequence(std::string_view s) noexcept;

/********** Main Function **********/

/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 **/
int main()
{
    // Отключаем синхронизацию с stdio для ускорения ввода-вывода
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string input_data;
    if (!(std::cin >> input_data))
    {
        return 0;
    }

    if (is_valid_sequence(input_data))
    {
        std::cout << "true" << '\n';
    }
    else
    {
        std::cout << "false" << '\n';
    }

    return 0;
}

/********** Function Implementation **********/

/**
 * Логика алгоритма:
 * 1. Итерируемся по строке.
 * 2. Если встречаем открывающую скобка — кладем в стек ОЖИДАЕМУЮ закрывающую.
 * 3. Если встречаем закрывающую — сравниваем её с той, что лежит на вершине стека.
 **/
bool is_valid_sequence(std::string_view s) noexcept
{
    // Стек для хранения ожидаемых закрывающих скобок
    std::stack<char> expectations;

    for (const char current_char : s)
    {
        // Проверяем тип открывающей скобки
        if (current_char == '(')
        {
            expectations.push(')');
        }
        else if (current_char == '{')
        {
            expectations.push('}');
        }
        else if (current_char == '[')
        {
            expectations.push(']');
        }
        else
        {
            // Если встречена закрывающая скобка:
            // 1. Стек не должен быть пустым (есть не закрытая пара)
            // 2. Текущая скобка должна совпадать с верхней в стеке
            if (expectations.empty() || expectations.top() != current_char)
            {
                return false;
            }
            // Удаляем успешно совпавшую пару
            expectations.pop();
        }
    }

    // В конце стек должен быть пуст (все открытые скобки получили свою пару)
    return expectations.empty();
}
