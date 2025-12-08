/**********************************************************************
 * @file script6.cpp
 * @brief Поиск длины самой длинной подстроки с неповторяющимися символами.
 *
 * @details Считывает строку и находит длину максимальной непрерывной
 * подстроки, в которой все символы различны. Использует алгоритм
 * скользящего окна (sliding window) для эффективного решения за O(N).
 *
 * @date 2025-01-07
 * @copyright Copyright (c) 2025
 **********************************************************************/

/********** Core **********/
#include <iostream>
#include <string>
#include <unordered_map>

/********** Main Function **********/
/**
 * @brief Точка входа программы.
 *
 * @return 0 при успешном выполнении
 */
int main(void)
{
    std::string str;

    // Считываем всю строку
    if (!std::getline(std::cin, str))
    {
        std::cout << 0 << std::endl;
        return 0;
    }

    // Обработка пустой строки (edge case)
    if (str.empty())
    {
        std::cout << 0 << std::endl;
        return 0;
    }

    // Словарь для хранения последней позиции каждого символа
    std::unordered_map<char, size_t> last_seen;

    size_t max_length = 0u;  // Максимальная длина подстроки
    size_t left = 0u;        // Левая граница окна

    // Проходим по строке правой границей окна
    for (size_t right = 0u; right < str.length(); ++right)
    {
        char c = str[right];

        auto it = last_seen.find(c);
        if (it != last_seen.end() && it->second >= left)
        {
            left = it->second + 1u;
        }

        last_seen[c] = right;

        size_t current_length = right - left + 1u;
        if (current_length > max_length)
        {
            max_length = current_length;
        }
    }

    std::cout << max_length << std::endl;
    return 0;
}
