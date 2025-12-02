/**********************************************************************
 * @file script5.cpp
 * @brief Интерпретатор команд Goal Parser.
 *
 * @date 2025-01-07
 * @copyright Copyright (c) 2025
 **********************************************************************/

/********** Core **********/
#include <cstdint>
#include <iostream>
#include <string>

/********** Data Types **********/
typedef uint32_t u32_t;  ///< Unsigned 32-bit integer
typedef size_t sz_t;     ///< Size type

/********** Function Prototypes **********/
/**
 * @brief Интерпретирует команды Goal Parser.
 *
 * @details Преобразует строку команд:
 * - "G" остаётся "G"
 * - "()" заменяется на "o"
 * - "(al)" заменяется на "al"
 *
 * @param[in] ref_command Ссылка на строку команд
 * @return std::string Интерпретированная строка
 *
 * @note Функция не модифицирует входную строку
 */
std::string interpret_goal_parser(const std::string &ref_command);

/********** Main Function **********/
/**
 * @brief Точка входа программы.
 *
 * @return 0 при успешном выполнении
 */
int main(void)
{
    std::string command;

    // Чтение строки команд из stdin
    if (!std::getline(std::cin, command))
    {
        return 0;
    }

    // Интерпретация команд
    std::string result = interpret_goal_parser(command);

    // Вывод результата
    std::cout << result << std::endl;

    return 0;
}

/********** Function Implementation **********/
std::string interpret_goal_parser(const std::string &ref_command)
{
    std::string result;

    // Резервируем память (оптимизация)
    result.reserve(ref_command.length());

    sz_t i = 0u;

    // Проход по всем символам строки команд
    while (i != ref_command.length())
    {
        if (ref_command[i] == 'G')
        {
            // "G" → "G"
            result += 'G';
            ++i;
        }
        else if (ref_command[i] == '(')
        {
            // Проверяем следующий символ после '('
            if (i + 1u < ref_command.length() && ref_command[i + 1u] == ')')
            {
                // "()" → "o"
                result += 'o';
                i += 2u;  // Пропускаем "()"
            }
            else if (i + 3u < ref_command.length() &&
                     ref_command[i + 1u] == 'a' &&
                     ref_command[i + 2u] == 'l' &&
                     ref_command[i + 3u] == ')')
            {
                // "(al)" → "al"
                result += "al";
                i += 4u;  // Пропускаем "(al)"
            }
            else
            {
                // Неожиданный символ (не должно происходить с корректным вводом)
                ++i;
            }
        }
        else
        {
            // Пропускаем неожиданные символы
            ++i;
        }
    }

    return result;
}
