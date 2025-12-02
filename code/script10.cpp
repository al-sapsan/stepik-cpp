/**********************************************************************
 * @file script10.cpp
 * @brief Вычисление "счёта" строки (STL version).
 *
 * @details Считывает строку и вычисляет её "счёт" — сумму абсолютных
 * разностей ASCII-кодов соседних символов. Использует STL контейнеры
 * и алгоритмы.
 *
 * @date 2025-01-07
 * @copyright Copyright (c) 2025
 **********************************************************************/

/********** Core **********/
#include <cstdint>
#include <iostream>
#include <string>
#include <cmath>

/********** Data Types **********/
typedef uint32_t u32_t;  ///< Unsigned 32-bit integer
typedef int32_t i32_t;   ///< Signed 32-bit integer
typedef size_t sz_t;     ///< Size type

/********** Function Prototypes **********/
/**
 * @brief Вычисляет "счёт" строки.
 *
 * @details Счёт строки — это сумма абсолютных разностей ASCII-кодов
 * соседних символов. Для строки длиной меньше 2 символов возвращает 0.
 *
 * @param[in] ref_str Ссылка на строку
 * @return u32_t Счёт строки
 *
 * @note Функция не модифицирует входную строку
 */
u32_t calculate_string_score(const std::string &ref_str);

/********** Main Function **********/
/**
 * @brief Точка входа программы.
 *
 * @return 0 при успешном выполнении
 */
int main(void)
{
    std::string input_str;

    // Чтение строки из stdin
    if (!std::getline(std::cin, input_str))
    {
        std::cout << "0" << std::endl;
        return 0;
    }

    // Вычисление счёта строки
    u32_t score_u32 = calculate_string_score(input_str);

    // Вывод результата
    std::cout << score_u32 << std::endl;

    return 0;
}

/********** Function Implementation **********/
u32_t calculate_string_score(const std::string &ref_str)
{
    // Если длина строки меньше 2, счёт равен 0
    sz_t len = ref_str.length();
    if (len < 2u)
    {
        return 0u;
    }

    u32_t total_score_u32 = 0u;

    // Проход по всем соседним парам символов
    for (sz_t i = 0u; i < (len - 1u); ++i)
    {
        // Получение ASCII-кодов соседних символов
        i32_t ascii_current_i32 = static_cast<i32_t>(ref_str[i]);
        i32_t ascii_next_i32 = static_cast<i32_t>(ref_str[i + 1u]);

        // Вычисление абсолютной разности
        i32_t diff_i32 = std::abs(ascii_current_i32 - ascii_next_i32);

        // Добавление к общему счёту
        total_score_u32 += static_cast<u32_t>(diff_i32);
    }

    return total_score_u32;
}
