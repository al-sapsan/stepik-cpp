/**********************************************************************
 * @file script3.cpp
 * @brief Обезвреживание IPv4-адреса (defanged IP).
 *
 * @details Считывает корректный IPv4-адрес и заменяет каждую точку "."
 * на "[.]", создавая обезвреженную версию адреса.
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
 * @brief Обезвреживает IPv4-адрес.
 *
 * @details Заменяет каждую точку "." на "[.]" в IP-адресе.
 * Например: "1.1.1.1" -> "1[.]1[.]1[.]1"
 *
 * @param[in] ref_ip Ссылка на строку с IPv4-адресом
 * @return std::string Обезвреженный IP-адрес
 *
 * @note Функция не модифицирует входную строку
 */
std::string defang_ip_address(const std::string &ref_ip);

/********** Main Function **********/
/**
 * @brief Точка входа программы.
 *
 * @return 0 при успешном выполнении
 */
int main(void)
{
    std::string ip_address;

    // Чтение IPv4-адреса из stdin
    if (!std::getline(std::cin, ip_address))
    {
        return 0;
    }

    // Обезвреживание IP-адреса
    std::string defanged_ip = defang_ip_address(ip_address);

    // Вывод результата
    std::cout << defanged_ip << std::endl;

    return 0;
}

/********** Function Implementation **********/
std::string defang_ip_address(const std::string &ref_ip)
{
    std::string result;

    // Резервируем память для результата (оптимизация)
    // Максимум 3 точки, каждая заменяется на "[.]" (+2 символа)
    result.reserve(ref_ip.length() + 6u);

    // Проход по всем символам входной строки
    for (sz_t i = 0u; i != ref_ip.length(); ++i)
    {
        if (ref_ip[i] == '.')
        {
            // Заменяем точку на "[.]"
            result += "[.]";
        }
        else
        {
            // Копируем символ как есть
            result += ref_ip[i];
        }
    }

    return result;
}
