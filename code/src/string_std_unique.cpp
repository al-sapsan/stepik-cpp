/**********************************************************************
 * @file script5.cpp
 * @brief Удаление подряд идущих одинаковых символов из строки.
 *
 * @details Считывает строку и заменяет все последовательности
 * одинаковых символов одним символом. Решение выполняется in-place
 * без создания дополнительных строковых переменных.
 *
 * @date 2025-01-07
 * @copyright Copyright (c) 2025
 **********************************************************************/

/********** Core **********/
#include <iostream>
#include <string>
#include <algorithm>    // for std::unique

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
        return 0;
    }

    auto new_end = std::unique(str.begin(), str.end());
    str.erase(new_end, str.end());

    std::cout << str << '\n';

    return 0;
}
