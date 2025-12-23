/************************************************************************
 * @file script1.cpp
 * @brief Программа для сортировки списка участников соревнований
 * @details Участники сортируются по убыванию очков, а при равенстве — 
 * лексикографически по имени.
 *
 * @version 1.0
 * @date 
 * @copyright Copyright (c) 2025 Oleg Sokolov
 *************************************************************************/

/********** Core **********/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/************ Structure Definition ***********/

/**
 * @brief Класс, представляющий участника соревнования
 */
struct Participant
{
    std::string name; ///< Имя участника
    int score;        ///< Количество набранных очков

    /**
     * @brief Оператор сравнения для выполнения условий задачи
     * @details Сортировка: score (desc), then name (asc)
     * @param other Другой участник для сравнения
     * @return true если текущий участник должен стоять выше (в контексте std::greater)
     */
    [[nodiscard]] bool operator>(const Participant& other) const noexcept
    {
        if (score != other.score)
        {
            return score > other.score;
        }
        return name < other.name;
    }
};

/********** Main Function **********/
/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 **/
int main()
{
    // Оптимизация потоков ввода-вывода
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t count = 0;
    if (!(std::cin >> count))
    {
        return 0;
    }

    std::vector<Participant> participants;
    participants.reserve(count);

    for (size_t i = 0; i < count; ++i)
    {
        std::string name;
        int score = 0;
        if (std::cin >> name >> score)
        {
            participants.push_back({ std::move(name), score });
        }
    }

    // Применяем std::greater, который вызывает перегруженный operator>
    std::ranges::sort(participants, std::greater<Participant>{});

    for (const auto& [name, score] : participants)
    {
        std::cout << name << " " << score << "\n";
    }

    return 0;
}
