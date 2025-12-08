/**********************************************************************
 * @file script4.cpp
 * @brief Удаление всех пробелов из строки.
 *
 * @details Считывает строку, содержащую буквы, цифры и пробелы,
 * и удаляет все пробелы из неё. Пробелы могут находиться в любом
 * месте строки, включая конец.
 *
 * @date 2025-01-07
 * @copyright Copyright (c) 2025
 **********************************************************************/

/********** Core **********/
#include <iostream>
#include <string>
#include <algorithm> // for std::remove_if
#include <cctype>    // for std::isspace

/********** Main Function **********/
/**
 * @brief Точка входа программы.
 *
 * @return 0 при успешном выполнении
 */
int main(void)
{
    std::string input_str;

    // Считываем всю строку, включая пробелы
    if (!std::getline(std::cin, input_str))
        {
            return 0;
        }

    input_str.erase(std::remove_if(input_str.begin(), input_str.end(), ::isspace), input_str.end());

    std::cout << input_str << std::endl;

    return 0;
}
