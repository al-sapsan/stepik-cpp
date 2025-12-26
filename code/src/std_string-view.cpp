/************************************************************************
 * @file script9.cpp
 * @brief Система управления задачами на базе std::queue (FIFO)
 *
 * @version 1.0
 * @date 
 * @copyright Copyright (c) 2025 Oleg Sokolov. All rights reserved
 *************************************************************************/

/********** Core **********/
#include <iostream>
#include <string>
#include <queue>
#include <string_view>

/********** Constants **********/
constexpr std::string_view CMD_ADD = "add";
constexpr std::string_view CMD_PROCESS = "process";
constexpr std::string_view CMD_EMPTY = "empty";

/********** Function Prototypes **********/

/**
 * @brief Запуск цикла обработки команд управления задачами
 * * Читает количество операций и выполняет соответствующие действия:
 * добавление, обработка или проверка очереди.
 */
void run_task_manager();

/********** Main Function **********/

/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 **/
int main()
{
    // Отключение синхронизации с C-style IO для ускорения ввода/вывода
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_task_manager();

    return 0;
}

/********** Function Implementation **********/

/**
 * @brief Реализация логики управления задачами
 */
void run_task_manager()
{
    size_t operations_count{ 0 };
    if (!(std::cin >> operations_count))
    {
        return;
    }

    std::queue<std::string> task_queue;
    std::string command;

    for (size_t i = 0; i < operations_count; ++i)
    {
        if (!(std::cin >> command))
            break;

        if (command == CMD_ADD)
        {
            std::string task_name;
            std::cin >> task_name;
            task_queue.push(std::move(task_name));
        }
        else if (command == CMD_PROCESS)
        {
            if (task_queue.empty())
            {
                std::cout << "Queue is empty\n";
            }
            else
            {
                std::cout << task_queue.front() << "\n";
                task_queue.pop();
            }
        }
        else if (command == CMD_EMPTY)
        {
            if (task_queue.empty())
            {
                std::cout << "Queue is empty\n";
            }
            else
            {
                std::cout << "Queue is not empty\n";
            }
        }
    }
}
