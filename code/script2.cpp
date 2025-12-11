/**********************************************************************
 * @file script2.cpp
 * @brief Работа с очередью планет и фильтрация по количеству спутников.
 *
 * @details Программа создаёт очередь планет std::deque<PLANET>,
 * добавляет планеты в начало очереди и выводит названия планет
 * с количеством спутников менее 3.
 *
 * @date 2025-01-01
 * @copyright Copyright (c) 2025
 **********************************************************************/

/********** Core **********/
#include <deque>
#include <iostream>
#include <string>

/********** Structures **********/
/**
 * @brief Структура, описывающая планету.
 */
struct PLANET
{
    std::string name;      // Название планеты
    double diameter = 0.0; // Диаметр (в км)
    unsigned int moons = 0; // Количество спутников
};

/********** Main Function **********/
/**
 * @brief Точка входа программы.
 *
 * @return 0 при успешном выполнении
 */
int main(void)
{
    std::deque<PLANET> planets;

    /* Add planets to the front of the deque */
    planets.push_front({"Меркурий", 4879, 0});
    planets.push_front({"Сатурн", 116460, 83});
    planets.push_front({"Венера", 12104, 0});
    planets.push_front({"Юпитер", 139820, 79});
    planets.push_front({"Марс", 6779, 2});

    /* Output planets with less than 3 moons */
    bool first = true;
    for (const auto& planet : planets)
    {
        if (planet.moons < 3)
        {
            if (!first)
            {
                std::cout << ' ';
            }
            std::cout << planet.name;
            first = false;
        }
    }
    std::cout << '\n';

    return 0;
}