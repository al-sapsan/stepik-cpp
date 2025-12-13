/**********************************************************************
 * @file script5.cpp
 * @brief Управление очередью телепорта с приоритетами и инспекциями.
 *
 * @details Программа моделирует работу телепорта в секретной лаборатории.
 * Учёные (SCIENTIST) имеют приоритет и заходят в начало очереди,
 * испытуемые (TESTSUBJECT) становятся в конец очереди,
 * инспектор (INSPECTOR) отправляет до 3 человек в телепорт.
 *
 * @date 2025-01-01
 * @copyright Copyright (c) 2025
 **********************************************************************/

/********** Core **********/
#include <deque>
#include <iostream>
#include <string>
#include <vector>

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

    std::deque<std::string> queue;
    std::vector<std::string> teleported;

    /* Process events */
    for (int i = 0; i < n; ++i)
    {
        std::string first_word;
        std::cin >> first_word;

        if (first_word == "INSPECTOR")
        {
            /* Send up to 3 people through teleport */
            int count = 0;
            while (!queue.empty() && count < 3)
            {
                teleported.push_back(queue.front());
                queue.pop_front();
                ++count;
            }
        }
        else
        {
            /* It's a person arriving */
            std::string type;
            std::cin >> type;

            if (type == "SCIENTIST")
            {
                queue.push_front(first_word);
            }
            else // TESTSUBJECT
            {
                queue.push_back(first_word);
            }
        }
    }

    /* Send remaining people through teleport */
    while (!queue.empty())
    {
        teleported.push_back(queue.front());
        queue.pop_front();
    }

    /* Output people in order they were sent through teleport */
    for (const auto& person : teleported)
    {
        std::cout << person << '\n';
    }

    return 0;
}
