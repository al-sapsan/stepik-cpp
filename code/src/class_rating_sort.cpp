/************************************************************************
 * @file script9.cpp
 * @brief Программа для сортировки участников шахматного турнира
 *
 * @version 1.1 (C++20)
 * @date 
 * @copyright Copyright (c) 2025 Oleg Sokolov. All rights reserved
 *************************************************************************/

/********** Core **********/
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

/********** Typedefs **********/
using u32_t = uint32_t;
using i32_t = int32_t;

/************ Class Definition ***********/

/**
 * @brief Класс, представляющий участника турнира
 */
class Participant
{
  public:
    u32_t id;     ///< Уникальный идентификатор
    i32_t rating; ///< Рейтинг игрока
    u32_t age;    ///< Возраст игрока

    /**
     * @brief Конструктор участника
     */
    Participant(u32_t p_id, i32_t p_rating, u32_t p_age)
        : id(p_id), rating(p_rating), age(p_age)
    {
    }

    /**
     * @brief Создает ключ для лексикографического сравнения
     * @return Кортеж со значениями в порядке приоритета сортировки
     * @note Рейтинг инвертирован для сортировки по убыванию
     */
    [[nodiscard]] auto make_sort_key() const
    {
        return std::tie(rating, age, id);
    }
};

/********** Main Function **********/
/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 */
int main()
{
    u32_t n;
    if (!(std::cin >> n))
        return 0;

    // Резервируем память для избежания лишних аллокаций
    std::vector<Participant> players;
    players.reserve(n);

    /********** Data Input **********/
    for (size_t i = 0; i < n; ++i)
    {
        u32_t id, age;
        i32_t rating;
        std::cin >> id >> rating >> age;
        players.emplace_back(id, rating, age);
    }

    /********** Sorting Logic **********/
    /**
     * Используем стандартный std::sort с итераторами.
     * Сравнение реализовано через лямбда-выражение.
     */
    std::sort(players.begin(), players.end(), [](const Participant& a, const Participant& b)
              {
        // 1. Сначала проверяем рейтинг (по убыванию)
        if (a.rating != b.rating) 
        {
            return a.rating > b.rating;
        }
        // 2. Затем возраст (по возрастанию)
        if (a.age != b.age) 
        {
            return a.age < b.age;
        }
        // 3. Наконец, ID (по возрастанию)
        return a.id < b.id; });

    /********** Output **********/
    for (const auto& player : players)
    {
        std::cout << player.id << " "
                  << player.rating << " "
                  << player.age << "\n";
    }

    return 0;
}
