/************************************************************************
 * @file script1.cpp
 * @brief Обработка строк (удаление цифр и ближайших букв слева)
 *
 * @version 1.2
 * @date 
 * @copyright Copyright (c) 2025 Oleg Sokolov. All rights reserved
 *************************************************************************/

/********** Core **********/
#include <iostream>
#include <string>
#include <cctype>

/********** Function Prototypes **********/

/**
 * @brief Обрабатывает строку согласно правилам задачи
 * * @param[in] s Входная строка
 * @return std::string Обработанная строка
 **/
[[nodiscard]] std::string
process_string(const std::string& s);

/********** Main Function **********/

/**
 * @brief Точка входа
 * @return Код завершения
 **/
int main()
{
    std::string input;

    // Чтение строк до конца потока ввода
    while (std::cin >> input)
    {
        if (input == "exit")
            break;
        std::cout << process_string(input) << std::endl;
    }

    return 0;
}

/********** Function Implementation **********/

[[nodiscard]] std::string
process_string(const std::string& s)
{
    std::string result;
    result.reserve(s.size());

    for (const char ch : s)
    {
        const auto u_ch = static_cast<unsigned char>(ch);

        if (std::isdigit(u_ch))
        {
            // Если есть символ слева и это не цифра — удаляем его (pop_back)
            if (!result.empty() && !std::isdigit(static_cast<unsigned char>(result.back())))
            {
                result.pop_back();
            }
            else
            {
                result.push_back(ch);
            }
        }
        else
        {
            result.push_back(ch);
        }
    }

    return result;
}
