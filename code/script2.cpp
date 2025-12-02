/**********************************************************************
 * @file script2.cpp
 * @brief Вычисление "счёта" строки — сумма абсолютных разностей ASCII соседних символов.
 *
 * @details Считывает одну строку `s` (включая пробелы) и вычисляет сумму
 * |s[i] - s[i-1]| для всех соседних пар символов. Выводит целое число — сумму.
 *
 * @date 2025-12-01
 * @copyright Copyright (c) 2025
 **********************************************************************/

/********** Core **********/
#include <cstdint>
#include <cstdio>

/********** Main Function **********/
/**
 * @brief Точка входа программы.
 *
 * @return 0 при успешном выполнении
 */
int main(void)
{
    static constexpr size_t BUF_SZ = 8192u;
    char buf[BUF_SZ];

    if (std::fgets(buf, static_cast<int>(BUF_SZ), stdin) == nullptr)
    {
        std::printf("0\n");
        return 0;
    }

    /* determine length (exclude terminating null and newline) */
    size_t len = 0u;
    for (size_t i = 0u; i != BUF_SZ; ++i)
    {
        if (buf[i] == '\0')
        {
            len = i;
            break;
        }
    }

    /* strip trailing newline/carriage returns */
    while (len != 0u)
    {
        char c = buf[len - 1u];
        if (c == '\n' || c == '\r')
        {
            --len;
            continue;
        }
        break;
    }

    long long sum_i64 = 0;
    if (len > 1u)
    {
        for (size_t i = 1u; i != len; ++i)
        {
            int32_t a_i32 = static_cast<int32_t>(buf[i]);
            int32_t b_i32 = static_cast<int32_t>(buf[i - 1u]);
            int32_t diff_i32 = a_i32 - b_i32;
            if (diff_i32 < 0)
                diff_i32 = -diff_i32;
            sum_i64 += static_cast<long long>(diff_i32);
        }
    }

    std::printf("%lld\n", sum_i64);
    return 0;
}
