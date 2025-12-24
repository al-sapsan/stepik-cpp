/************************************************************************
 * @file script8.cpp
 * @brief Flight sorting system for airport tracking
 *
 * @version 1.0 (C++20)
 * @date 
 * @copyright Copyright (c) 2025 Oleg Sokolov. All rights reserved 
 *************************************************************************/

/********** Core **********/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <compare>

/********** Typedefs **********/
using u16_t = uint16_t;

/************ Structure Definition ***********/

/**
 * @brief Структура, представляющая информацию о рейсе
 */
struct Flight
{
    std::string departure_time; // Время в формате HH:MM
    std::string airline;        // Название авиакомпании
    int flight_number;          // Номер рейса

    /**
     * @brief Оператор лексикографического сравнения (C++20)
     * * Сравнивает рейсы последовательно:
     * 1. По времени вылета
     * 2. По названию авиакомпании
     * 3. По номеру рейса
     */
    auto operator<=>(const Flight&) const = default;
};

/********** Main Function **********/
/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 **/
int main()
{
    size_t n;
    if (!(std::cin >> n))
    {
        return 0;
    }

    // Резервируем память для вектора рейсов
    std::vector<Flight> flights;
    flights.reserve(n);

    // Чтение данных
    for (size_t i = 0; i < n; ++i)
    {
        Flight f;
        std::cin >> f.departure_time >> f.airline >> f.flight_number;
        flights.push_back(std::move(f));
    }

    // Сортировка с использованием std::sort и оператора <=>
    std::sort(flights.begin(), flights.end());

    // Вывод результатов
    for (const auto& [time, company, number] : flights)
    {
        std::cout << time << " " << company << " " << number << "\n";
    }

    return 0;
}
