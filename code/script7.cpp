/**********************************************************************
 * @file script7.cpp
 * @brief Управление заказами в кафе с использованием списка.
 *
 * @details Программа обрабатывает заказы в кафе, поддерживая операции:
 * - complete: удаление первого заказа из списка
 * - urgent X: добавление срочного заказа X в начало списка
 *
 * @version 1.0
 * @date 2025-11-28
 *
 * @copyright Copyright (c) 2025
 **********************************************************************/

/********** Core **********/
#include <cstddef>
#include <iostream>
#include <list>
#include <string>

/********** Main Function **********/
/**
 * @brief Точка входа в программу.
 *
 * @details Считывает начальные заказы, обрабатывает операции
 * complete и urgent, выводит итоговый список заказов.
 *
 * @return 0 при успешном завершении
 */
int main(void)
{
    int n;
    std::cin >> n;

    std::list<std::string> orders;

    // Чтение заказов
    for (int i = 0; i < n; ++i)
    {
        std::string order;
        std::cin >> order;
        orders.push_back(order);
    }

    int m;
    std::cin >> m;

    // Обработка команд
    for (int i = 0; i < m; ++i)
    {
        std::string command;
        std::cin >> command;

        if (command == "complete")
        {
            if (!orders.empty())
                orders.pop_front();
        }
        else // urgent
        {
            std::string item;
            std::cin >> item;
            orders.push_front(item);
        }
    }

    // Вывод
    if (orders.empty())
    {
        std::cout << "empty\n";
    }
    else
    {
        // По примерам требуется пробел в конце
        for (const auto& order : orders)
        {
            std::cout << order << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
