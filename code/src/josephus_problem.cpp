/************************************************************************
 * @file script6.cpp
 * @brief Решение задачи Иосифа Флавия (раздача подарков Громозекой)
 * @note Используется std::queue для симуляции кругового движения.
 *
 * @version 1.1 (Modern C++20)
 * @date 
 * @copyright Copyright (c) 2025 Oleg Sokolov. All rights reserved
 *************************************************************************/

/********** Core **********/
#include <iostream>
#include <queue>
#include <numeric>
#include <vector>

/********** Typedefs **********/
typedef uint32_t u32_t;

/********** Function Prototypes **********/

/**
 * @brief Симуляция раздачи подарков детям с использованием очереди
 *
 * @param[in] n Общее количество детей
 * @param[in] k Шаг раздачи (каждый k-й ребенок получает подарок)
 */
void run_gift_distribution(u32_t n, u32_t k);

/********** Main Function **********/

/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 **/
int main(void)
{
    u32_t n_children{ 0 };
    u32_t k_step{ 0 };

    // Считывание входных данных
    if (!(std::cin >> n_children >> k_step))
    {
        return 0;
    }

    run_gift_distribution(n_children, k_step);

    return 0;
}

/********** Function Implementation **********/

/**
 * @brief Реализация алгоритма распределения подарков через std::queue
 */
void run_gift_distribution(u32_t n, u32_t k)
{
    if (n == 0)
    {
        return;
    }

    std::queue<u32_t> children;
    for (u32_t i = 1; i <= n; ++i)
    {
        children.push(i);
    }

    bool is_first_output = true;

    while (!children.empty())
    {
        // Вычисляем эффективное количество перестановок
        // Нам нужно пропустить (k-1) ребенка
        u32_t rotations = (k - 1) % children.size();

        for (u32_t i = 0; i < rotations; ++i)
        {
            // Перемещаем ребенка из начала в конец очереди (имитация круга)
            children.push(children.front());
            children.pop();
        }

        // k-й ребенок получает подарок и выходит из круга
        if (!is_first_output)
        {
            std::cout << " ";
        }
        std::cout << children.front();
        is_first_output = false;

        children.pop();
    }

    std::cout << "\n";
}
