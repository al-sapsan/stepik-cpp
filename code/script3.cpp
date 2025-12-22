/************************************************************************
 * @file word_freq.cpp
 * @brief Программа для подсчета частоты слов с сортировкой (Modern C++20)
 * * @note Сложность: O(N log N) для сортировки, где N — количество слов.
 *
 * @version 1.0
 * @date 2023-10-27
 * @copyright Copyright (c) 2025
 *************************************************************************/

/********** includes **********/
#include <algorithm>
#include <iostream>
#include <map>
#include <ranges>
#include <string>
#include <vector>

/********** Typedefs **********/
typedef uint32_t u32_t;

/********** Main Function **********/
/**
 * @brief Точка входа в программу
 * * Читает количество слов N, затем N слов. Подсчитывает частоту
 * вхождения каждого слова, сортирует их по убыванию частоты
 * (при равенстве — по алфавиту) и выводит результат.
 * * @return Код завершения
 **/
int main(void)
{
    // Отключаем синхронизацию для ускорения ввода-вывода
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    u32_t count_u32 = 0;
    if (!(std::cin >> count_u32))
    {
        return 0;
    }

    // Используем std::map для автоматической сортировки по алфавиту при вставке
    std::map<std::string, u32_t> word_map;

    for (size_t i = 0; i < count_u32; ++i)
    {
        std::string temp_word_s;
        if (std::cin >> temp_word_s)
        {
            word_map[temp_word_s]++;
        }
    }

    // Переносим данные в вектор для кастомной сортировки
    std::vector<std::pair<std::string, u32_t>> sorted_words_v(word_map.begin(), word_map.end());

    /**
     * Лямбда-компаратор:
     * 1. Сначала сравниваем частоты (по убыванию)
     * 2. Если частоты равны, сравниваем строки (по возрастанию/алфавиту)
     */
    std::ranges::sort(sorted_words_v, [](const auto& lhs, const auto& rhs)
                      {
                          if (lhs.second != rhs.second)
                          {
                              return lhs.second > rhs.second; // Частота по убыванию
                          }
                          return lhs.first < rhs.first; // Алфавит по возрастанию
                      });

    for (const auto& [word, freq] : sorted_words_v)
    {
        std::cout << word << " " << freq << "\n";
    }

    return 0;
}
