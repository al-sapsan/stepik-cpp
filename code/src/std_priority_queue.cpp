/************************************************************************
 * @file script8.cpp
 * @brief Менеджер задач с использованием очереди с приоритетами
 *
 * @version 1.0 (C++20)
 * @date 
 * @copyright Copyright (c) 2025 Oleg Sokolov. All rights reserved
 *************************************************************************/

/********** Core **********/
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cstdint>

/********** Typedefs **********/
using u32_t = uint32_t;
using i32_t = int32_t;

/************ Structure Definition ***********/

/**
 * @brief Структура для представления задачи
 */
struct Task
{
    std::string name; ///< Название задачи
    i32_t priority;   ///< Значение приоритета (P)

    /**
     * @brief Оператор сравнения для очереди с приоритетами
     * @param other Другая задача для сравнения
     * @return true если приоритет текущей задачи меньше
     */
    [[nodiscard]] auto operator<(const Task& other) const noexcept -> bool
    {
        // В std::priority_queue элемент с "наибольшим" значением выходит первым.
        // Поэтому используем стандартное сравнение по приоритету для Max-Heap.
        return priority < other.priority;
    }
};

/********** Function Prototype **********/

/**
 * @brief Выполняет симуляцию обработки очереди задач
 * @return i32_t Статус завершения
 */
i32_t run_simulation();

/********** Main Function **********/

/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 **/
int main()
{
    // Оптимизация потоков ввода-вывода (ускоряет работу с большими N)
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    return run_simulation();
}

/********** Function Implementation **********/

/**
 * @brief Реализация цикла обработки команд
 */
i32_t run_simulation()
{
    u32_t n_operations{ 0 };
    if (!(std::cin >> n_operations))
    {
        return 0;
    }

    // Использование адаптера std::priority_queue (Max-Heap по умолчанию)
    std::priority_queue<Task> task_queue;

    for (u32_t i = 0; i < n_operations; ++i)
    {
        std::string command;
        std::cin >> command;

        if (command == "add")
        {
            std::string name;
            i32_t priority;
            std::cin >> name >> priority;
            // Добавление задачи: O(log N)
            task_queue.push(Task{ std::move(name), priority });
        }
        else if (command == "process")
        {
            if (task_queue.empty())
            {
                std::cout << "Queue is empty\n";
            }
            else
            {
                // Извлечение задачи с наивысшим приоритетом: O(log N)
                std::cout << task_queue.top().name << "\n";
                task_queue.pop();
            }
        }
        else if (command == "empty")
        {
            // Проверка на пустоту: O(1)
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

    return 0;
}
