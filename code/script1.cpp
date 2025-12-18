/*******************************************************************************
 * @file    unique_words.cpp
 * @brief   Программа для нахождения слов, встречающихся только в одном из двух текстов
 *
 * @version 1.1
 * @date    2025-12-17
 * @copyright Copyright (c) 2025
 ******************************************************************************/

/********** Includes **********/
#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

/********** Function Prototypes **********/

/**
 * @brief Разбивает строку на множество уникальных слов
 *
 * @param[in] text Входная строка
 * @return Множество уникальных слов
 */
std::set<std::string>
split_text_to_set(const std::string& text);

/**
 * @brief Находит симметрическую разность двух множеств слов
 *
 * @param[in] words_left  Первое множество
 * @param[in] words_right Второе множество
 * @return Вектор слов, встречающихся только в одном из текстов (отсортирован)
 */
std::vector<std::string>
find_symmetric_difference(const std::set<std::string>& words_left,
                          const std::set<std::string>& words_right);

/********** Main Function **********/

/**
 * @brief Точка входа в программу
 *
 * @return Код завершения (0 — успех)
 */
int main(void)
{
    std::string text_left;
    std::string text_right;

    std::getline(std::cin, text_left);
    std::getline(std::cin, text_right);

    const std::set<std::string> words_left = split_text_to_set(text_left);
    const std::set<std::string> words_right = split_text_to_set(text_right);

    const std::vector<std::string> unique_words =
        find_symmetric_difference(words_left, words_right);

    if (unique_words.empty())
    {
        std::cout << "NO\n";
    }
    else
    {
        for (const std::string& word : unique_words)
        {
            std::cout << word << " ";
        }
        std::cout << "\n";
    }

    return 0;
}

/********** Function Implementation **********/

std::set<std::string>
split_text_to_set(const std::string& text)
{
    std::set<std::string> words;
    std::istringstream stream(text);
    std::string token;

    while (stream >> token)
    {
        words.insert(token);
    }

    return words;
}

std::vector<std::string>
find_symmetric_difference(const std::set<std::string>& words_left,
                          const std::set<std::string>& words_right)
{
    std::vector<std::string> result;

    for (const std::string& word : words_left)
    {
        if (words_right.find(word) == words_right.end())
        {
            result.push_back(word);
        }
    }

    for (const std::string& word : words_right)
    {
        if (words_left.find(word) == words_left.end())
        {
            result.push_back(word);
        }
    }

    std::sort(result.begin(), result.end());
    return result;
}
