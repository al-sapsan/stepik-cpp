/**********************************************************************
 * @file script1.cpp
 * @brief Симуляция истории браузера с навигацией.
 *
 * @details Программа обрабатывает команды браузера:
 * - visit X: переход на страницу X
 * - back: возврат на предыдущую страницу
 * - forward: переход вперед (если использовался back)
 * - print: вывод текущей страницы
 *
 * @date 2025-01-01
 * @copyright Copyright (c) 2025
 **********************************************************************/

/********** Core **********/
#include <iostream>
#include <list>
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

    std::list<std::string> history;
    auto current = history.end(); // Итератор на текущую страницу

    for (int i = 0; i < n; ++i)
    {
        std::string command;
        std::cin >> command;

        if (command == "visit")
        {
            std::string page;
            std::cin >> page;

            // Удаляем "будущую" историю после текущей позиции
            if (current != history.end())
            {
                auto temp = current;
                ++temp; // Начинаем удалять со следующего элемента
                history.erase(temp, history.end());
            }

            // Добавляем новую страницу
            history.push_back(page);
            current = --history.end();
        }
        else if (command == "back")
        {
            if (current != history.begin() && !history.empty())
            {
                --current;
            }
        }
        else if (command == "forward")
        {
            if (current != history.end() && !history.empty())
            {
                auto temp = current;
                ++temp;
                if (temp != history.end())
                {
                    ++current;
                }
            }
        }
        else if (command == "print")
        {
            if (!history.empty() && current != history.end())
            {
                std::cout << *current << '\n';
            }
            else
            {
                std::cout << "empty\n";
            }
        }
    }

    return 0;
}
