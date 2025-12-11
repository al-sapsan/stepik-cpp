/**********************************************************************
 * @file script4.cpp
 * @brief Умный лифт с обслуживанием пассажиров по направлению движения.
 *
 * @details Программа моделирует работу умного лифта в небоскрёбе.
 * Пассажиры, спускающиеся вниз (DOWN), заходят в начало очереди,
 * пассажиры, поднимающиеся вверх (UP), заходят в конец очереди.
 * Выводятся имена пассажиров в порядке их выхода из лифта.
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

    std::deque<std::string> elevator;

    /* Board passengers into elevator */
    for (int i = 0; i < n; ++i)
    {
        std::string name;
        std::string direction;
        std::cin >> name >> direction;

        if (direction == "DOWN")
        {
            elevator.push_front(name);
        }
        else // UP
        {
            elevator.push_back(name);
        }
    }

    /* Output passengers in exit order */
    for (const auto& passenger : elevator)
    {
        std::cout << passenger << '\n';
    }

    return 0;
}