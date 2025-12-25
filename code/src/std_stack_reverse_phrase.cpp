/************************************************************************
 * @file script4.cpp
 * @brief Текстовый редактор: инвертирование порядка слов с помощью std::stack
 * @note Гарантируется отсутствие лишних пробелов во входных данных.
 *
 * @version 1.1 (Modern C++20)
 * @date
 * @copyright Copyright (c) 2025 Oleg Sokolov. All rights reserved
 *************************************************************************/

/********** Core **********/
#include <iostream>
#include <string>
#include <stack>
#include <sstream>

/********** Function Prototypes **********/

/**
 * @brief Разделяет входную строку на слова и помещает их в стек
 * * @param[in] text Исходная строка для обработки
 * @return std::stack<std::string> Стек со словами (LIFO)
 * * @note Оператор >> считывает слова, разделенные пробелами
 **/
[[nodiscard]] std::stack<std::string>
fill_stack_with_words(const std::string& text);

/**
 * @brief Собирает слова из стека в одну строку в обратном порядке
 * * @param[in, out] words_stack Стек со словами (будет очищен)
 * @return std::string Результирующая строка
 **/
[[nodiscard]] std::string
build_string_from_stack(std::stack<std::string>& words_stack);

/********** Main Function **********/

/**
 * @brief Точка входа в программу
 * * @return Код завершения (0 — успешно)
 **/
int main(void)
{
    std::string input_line;

    // Считываем всю строку целиком
    if (!std::getline(std::cin, input_line) || input_line.empty())
    {
        return 0;
    }

    // 1. Заполняем стек словами (порядок добавления: первое слово внизу)
    auto words_stack = fill_stack_with_words(input_line);

    // 2. Извлекаем слова (порядок извлечения: последнее слово первым) и выводим
    std::cout << build_string_from_stack(words_stack) << std::endl;

    return 0;
}

/********** Function Implementation **********/

/**
 * @brief Реализация заполнения стека
 **/
[[nodiscard]] std::stack<std::string>
fill_stack_with_words(const std::string& text)
{
    std::stack<std::string> words;
    std::istringstream stream(text);
    std::string word;

    while (stream >> word)
    {
        // Используем emplace для конструирования объекта внутри стека
        words.emplace(std::move(word));
    }

    return words;
}

/**
 * @brief Реализация сборки строки из стека
 **/
[[nodiscard]] std::string
build_string_from_stack(std::stack<std::string>& words_stack)
{
    std::string result;

    while (!words_stack.empty())
    {
        // Добавляем верхний (последний добавленный) элемент
        result += words_stack.top();
        words_stack.pop();

        // Добавляем пробел, если в стеке еще остались слова
        if (!words_stack.empty())
        {
            result += " ";
        }
    }

    return result;
}
