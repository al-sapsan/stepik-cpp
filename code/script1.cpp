/************************************************************************
 * @file script1.cpp
 * @brief Реализация очереди с поддержкой минимума через std::deque
 *
 * @version 1.1
 * @date 2023-10-27
 * @copyright Copyright (c) 2025 Oleg Sokolov. All rights reserved
 *************************************************************************/

/********** Core **********/
#include <iostream>
#include <deque>
#include <cstdint>

/********** Typedefs **********/
using i32 = int32_t;

/************ Class Prototype ***********/

/**
 * @brief Очередь с поддержкой минимума за амортизированное O(1).
 * Использует монотонную деку для хранения индексов или значений минимумов.
 */
class MinQueue
{
  private:
    std::deque<i32> main_queue; // Основное хранилище FIFO
    std::deque<i32> min_deque;  // Монотонная дека для минимумов

  public:
    /**
     * @brief Добавить элемент в очередь
     * @param val Значение для добавления
     * @note Поддерживает монотонность: удаляет все элементы больше текущего с конца деки
     */
    void push(i32 val)
    {
        main_queue.push_back(val);

        // Поддерживаем возрастающий порядок в min_deque
        while (!min_deque.empty() && min_deque.back() > val)
        {
            min_deque.pop_back();
        }
        min_deque.push_back(val);
    }

    /**
     * @brief Удалить первый элемент и вернуть минимум (с учетом удаляемого)
     * @return Текущий минимум или -1, если очередь пуста
     */
    i32 pop_and_get_min()
    {
        if (main_queue.empty())
        {
            return -1;
        }

        // Минимум всей очереди находится в начале монотонной деки
        i32 current_min = min_deque.front();

        // Если удаляемый элемент и есть текущий минимум — убираем его из min_deque
        if (main_queue.front() == min_deque.front())
        {
            min_deque.pop_front();
        }

        main_queue.pop_front();
        return current_min;
    }
};

/********** Main Function **********/
/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 */
int main()
{
    // Оптимизация стандартного I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i32 n;
    if (!(std::cin >> n))
    {
        return 0;
    }

    MinQueue q;

    for (i32 i = 0; i < n; ++i)
    {
        i32 val;
        if (!(std::cin >> val))
            break;

        if (val > 0)
        {
            q.push(val);
        }
        else
        {
            std::cout << q.pop_and_get_min() << "\n";
        }
    }

    return 0;
}
