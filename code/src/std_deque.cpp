/**********************************************************************
 * @file script3.cpp
 * @brief Посадка пассажиров на шаттл с учётом приоритета VIP.
 *
 * @details Программа моделирует посадку пассажиров на шаттл.
 * VIP-пассажиры садятся в начало (push_front), обычные пассажиры
 * садятся в конец (push_back). Затем выводятся имена пассажиров
 * в порядке их выхода из шаттла.
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
    if (!(std::cin >> n))
    {
       return 0;
    }

    std::deque<std::string> shuttle;

    for (int i = 0; i < n; ++i)
    {
        std::string name, type;
        std::cin >> name >> type;

        // Проверка корректности типа
        if (type != "VIP" && type != "REGULAR")
        {
            // Можно пропустить или завершить с ошибкой
            continue;
        }

        if (type == "VIP")
        {
            shuttle.push_front(name);  // LIFO для VIP
        }
        else  // REGULAR
        {
            shuttle.push_back(name);   // FIFO для обычных
        }
    }

    // Вывод
    for (const auto& passenger : shuttle)
    {
        std::cout << passenger << '\n';
    }
    return 0;
}
