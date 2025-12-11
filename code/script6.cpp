/**********************************************************************
 * @file script6.cpp
 * @brief Управление стопкой контрольных работ с запросами.
 *
 * @details Программа моделирует сдачу контрольных работ студентами.
 * Студенты кладут работы либо сверху (top), либо снизу (bottom) стопки.
 * Затем программа отвечает на запросы о том, чья работа находится
 * на указанной позиции в стопке.
 *
 * @date 2025-01-01
 * @copyright Copyright (c) 2025
 **********************************************************************/

/********** Core **********/
#include <deque>
#include <iostream>
#include <string>

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

    std::deque<std::string> stack;

    /* Build the stack of exam papers */
    for (int i = 0; i < n; ++i)
    {
        std::string surname;
        std::string position;
        std::cin >> surname >> position;

        if (position == "top")
        {
            stack.push_front(surname);
        }
        else // bottom
        {
            stack.push_back(surname);
        }
    }

    int m;
    std::cin >> m;

    /* Process queries */
    for (int i = 0; i < m; ++i)
    {
        int x;
        std::cin >> x;
        
        /* Output the surname at position x (1-based indexing) */
        std::cout << stack[x - 1] << '\n';
    }

    return 0;
}