/************************************************************************
 * @file script2.cpp
 * @brief Система обработки итогов голосования за лучшего учителя
 * @note Используется std::unordered_map для подсчета и std::vector для сортировки.
 * @warning Ограничение по N до 10^5, алгоритм работает за O(N log N).
 *
 * @version 1.0 (Modern C++20)
 * @date 2023-10-27
 * @copyright Copyright (c) 2025
 *************************************************************************/

/********** Core **********/
#include <algorithm>
#include <iostream>
#include <ranges>
#include <string>
#include <unordered_map>
#include <vector>

/********** Typedefs **********/
typedef std::string str_t;
typedef size_t u64_t;

/********** Constants **********/
constexpr u64_t MAX_VOTES = 100000;

/********** Class Prototypes ***********/

// == < Class VoteProcessor > == //
/**
 * @brief Класс для обработки и хранения результатов голосования
 */
class VoteProcessor
{
  private:
    /** Контейнер для хранения пар: Имя учителя -> Количество голосов */
    std::unordered_map<str_t, u64_t> vote_registry;

  public:
    /**
     * @brief Регистрирует голос за конкретного учителя
     * @param teacher_name Имя учителя
     */
    void add_vote(const str_t& teacher_name)
    {
        vote_registry[teacher_name]++;
    }

    /**
     * @brief Получает отсортированные результаты
     * @return Вектор пар (имя, голоса), отсортированный по правилам задачи
     */
    [[nodiscard]] auto get_sorted_results() const
    {
        // Перенос данных из map в vector для сортировки
        std::vector<std::pair<str_t, u64_t>> results(vote_registry.begin(), vote_registry.end());

        // Сортировка с использованием лямбда-выражения
        std::sort(results.begin(), results.end(), [](const auto& a, const auto& b)
                  {
                      if (a.second != b.second)
                      {
                          return a.second > b.second; // Убывание по количеству голосов
                      }
                      return a.first < b.first; // Алфавитный порядок при равенстве
                  });

        return results;
    }
};

/********** Main Function **********/
/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 **/
int main()
{
    // Оптимизация ввода-вывода
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    u64_t n_votes{ 0 };
    if (!(std::cin >> n_votes))
    {
        return 0;
    }

    VoteProcessor processor;

    // Чтение голосов
    for (size_t i = 0; i < n_votes; ++i)
    {
        str_t name;
        std::cin >> name;
        processor.add_vote(name);
    }

    // Получение и вывод результатов
    const auto final_results = processor.get_sorted_results();

    for (const auto& [name, count] : final_results)
    {
        std::cout << name << " " << count << "\n";
    }

    return 0;
}
