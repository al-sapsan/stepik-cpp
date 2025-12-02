/**********************************************************************
 * @file script10.cpp
 * @brief Длина последнего слова в строке.
 *
 * @details Считывает одну строку (включая пробелы) и возвращает длину
 * последнего слова — максимальной непрерывной последовательности символов
 * без пробелов. Если слов нет, возвращает 0.
 *
 * @date 2025-12-01
 * @copyright Copyright (c) 2025
 **********************************************************************/

/********** Core **********/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

/********** Main Function **********/
/**
 * @brief Точка входа программы.
 *
 * @return 0 при успешном выполнении
 */

int main()
{
    std::string s;
    std::getline(std::cin, s);

    // Удаляем пробелы в конце
    s.erase(std::find_if(s.rbegin(), s.rend(),
    [](unsigned char ch){ return !std::isspace(ch); }) .base(), s.end());

    // Находим последнее слово
    auto last_space = s.find_last_of(" \t\n\r");

    if (last_space == std::string::npos)
    {
        std::cout << s.length() << "\n";
    }
    else
    {
        std::cout << s.length() - last_space - 1 << "\n";
    }

    return 0;
}
