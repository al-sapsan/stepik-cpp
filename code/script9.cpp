/**********************************************************************
 * @file script9.cpp
 * @brief Управление запросами лифта с возможностью отмены.
 *
 * @details Программа обрабатывает последовательность запросов лифта:
 * - call X: добавить вызов на этаж X
 * - cancel: отменить последний вызов
 * - print: вывести все этажи в порядке вызова
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
 * @details Считывает количество запросов, обрабатывает команды
 * call, cancel и print, управляя маршрутом лифта.
 *
 * @return 0 при успешном завершении
 */
int main(void)
{
    int32_t n_i32 = 0;
    std::cin >> n_i32;

    std::deque<int32_t> floors_deque;

    // Обрабатываем запросы
    for (size_t i = 0; i < static_cast<size_t>(n_i32); i++)
    {
        std::string command_str;
        std::cin >> command_str;

        if (command_str == "call")
        {
            int32_t floor_i32 = 0;
            std::cin >> floor_i32;
            floors_deque.push_back(floor_i32);
        }
        else if (command_str == "cancel")
        {
            if (!floors_deque.empty())
            {
                floors_deque.pop_back();
            }
        }
        else if (command_str == "print")
        {
            if (floors_deque.empty())
            {
                std::cout << "empty\n";
            }
            else
            {
                for (const auto& floor : floors_deque)
                {
                    std::cout << floor << " ";
                }
                std::cout << "\n";
            }
        }
    }

    return 0;
}
