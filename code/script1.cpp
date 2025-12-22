/************************************************************************
 * @file script1.cpp
 * @brief Программа для поиска незавершивших турнир участников
 * @note Имена участников выводятся в порядке их регистрации.
 * @warning Имена чувствительны к регистру.
 *
 * @version 1.1
 * @date 2023-10-27
 * @copyright Copyright (c) 2025
 *************************************************************************/

/********** Core **********/
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

/********** Main Function **********/
/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 **/
int main()
{
    // Оптимизация стандартного ввода-вывода
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    /********** 1. Обработка зарегистрированных участников **********/
    size_t n_registered{ 0 };
    if (!(std::cin >> n_registered))
    {
        return 0;
    }

    // Храним порядок регистрации в vector
    std::vector<std::string> registered_order;
    registered_order.reserve(n_registered);

    for (size_t i = 0; i < n_registered; ++i)
    {
        std::string name;
        std::cin >> name;
        registered_order.push_back(std::move(name));
    }

    /********** 2. Обработка финишировавших участников **********/
    size_t m_finished{ 0 };
    if (!(std::cin >> m_finished))
    {
        // Если никто не финишировал, все зарегистрированные — прогульщики ))
        for (const auto& name : registered_order)
        {
            std::cout << name << "\n";
        }
        return 0;
    }

    // Используем unordered_set для проверки наличия имени за O(1)
    std::unordered_set<std::string> finished_names;
    finished_names.reserve(m_finished);

    for (size_t i = 0; i < m_finished; ++i)
    {
        std::string name;
        std::cin >> name;
        finished_names.insert(std::move(name));
    }

    /********** 3. Поиск и вывод отсутствующих **********/
    // Проходим по вектору зарегистрированных, чтобы сохранить исходный порядок
    for (const auto& name : registered_order)
    {
        // В C++20 используем .contains() для проверки наличия элемента в set
        if (!finished_names.contains(name))
        {
            std::cout << name << "\n";
        }
    }

    return 0;
}
