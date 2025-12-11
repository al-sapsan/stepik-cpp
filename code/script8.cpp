/**********************************************************************
 * @file script8.cpp
 * @brief Управление историей действий в текстовом редакторе.
 *
 * @details Программа обрабатывает последовательность действий:
 * - add X: добавить действие X в историю
 * - undo: удалить последнее действие из истории
 * - print: вывести все действия в порядке выполнения
 *
 * @version 1.0
 * @date 2025-11-28
 *
 * @copyright Copyright (c) 2025
 **********************************************************************/

/********** Core **********/
#include <cstddef>
#include <cstdint>
#include <deque>
#include <iostream>
#include <string>

/********** Main Function **********/
/**
 * @brief Точка входа в программу.
 *
 * @details Считывает количество операций, обрабатывает команды
 * add, undo и print, управляя историей действий редактора.
 *
 * @return 0 при успешном завершении
 */
int main(void)
{
    int32_t n_i32 = 0;
    std::cin >> n_i32;

    std::deque<std::string> history_deque;

    // Обрабатываем операции
    for (size_t i = 0; i < static_cast<size_t>(n_i32); i++)
    {
        std::string command_str;
        std::cin >> command_str;

        if (command_str == "add")
        {
            std::string action_str;
            std::cin >> action_str;
            history_deque.push_back(action_str);
        }
        else if (command_str == "undo")
        {
            if (!history_deque.empty())
            {
                history_deque.pop_back();
            }
        }
        else if (command_str == "print")
        {
            if (history_deque.empty())
            {
                std::cout << "empty\n";
            }
            else
            {
                for (const auto& action : history_deque)
                {
                    std::cout << action << " ";
                }
                std::cout << "\n";
            }
        }
    }

    return 0;
}