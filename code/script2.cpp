/**********************************************************************
 * @file script2.cpp
 * @brief Выводит уникальные слова из двух текстов.
 *
 * @details Программа считывает два текста, затем выводит уникальные
 * слова в алфавитном порядке. Если уникальных слов нет, выводит "NO".
 *
 * @version 1.1
 * @date 2025-07-07
 *
 * @copyright Copyright (c) 2025
 *********************************************************************/

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

/**
 * @brief Выводит уникальные слова из двух текстов.
 *
 * @param[in] text1 Первый текст
 * @param[in] text2 Второй текст
 */
void findUniqueWords(const std::string& text1, const std::string& text2)
{
    std::unordered_set<std::string> set1, set2;
    std::istringstream iss1(text1);
    std::istringstream iss2(text2);

    std::string word;
    while (iss1 >> word)
    {
        set1.insert(word);
    }

    while (iss2 >> word)
    {
        set2.insert(word);
    }

    // Вектор для хранения уникальных слов
    std::vector<std::string> uniqueWords;

    // Находим слова, которые есть только в первом тексте
    for (const auto& word : set1)
    {
        if (set2.count(word) == 0)
        {
            uniqueWords.push_back(word);
        }
    }

    // Находим слова, которые есть только во втором тексте
    for (const auto& word : set2)
    {
        if (set1.count(word) == 0)
        {
            uniqueWords.push_back(word);
        }
    }

    // Если нет уникальных слов
    if (uniqueWords.empty())
    {
        std::cout << "NO" << std::endl;
        return;
    }

    // Сортируем вектор
    std::sort(uniqueWords.begin(), uniqueWords.end());

    // Выводим результат
    for (const auto& word : uniqueWords)
    {
        std::cout << word << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief Основная функция программы.
 *
 * @return 0 в случае успешного завершения
 */
int main()
{
    std::string text1, text2;
    std::getline(std::cin, text1);
    std::getline(std::cin, text2);

    findUniqueWords(text1, text2);

    return 0;
}
