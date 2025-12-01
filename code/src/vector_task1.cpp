/**********************************************************************
 * @file script3.cpp
 * @brief Решение: поэлементная сумма двух векторов, заполненных 0..n-1 и 0..m-1.
 *
 * @details Программа читает два целых числа `n` и `m` (гарантируется n == m),
 * заполняет два вектора значениями 0..n-1 и 0..m-1 и выводит их поэлементную сумму.
 *
 * @date 2025-11-27
 * @copyright Copyright (c) 2025
 **********************************************************************/

/********** Core **********/
#include <cstdint>
#include <cstdio>
#include <vector>

/********** Main Function **********/
/**
 * @brief Точка входа программы.
 *
 * Читает `n` и `m`, формирует два `std::vector<int32_t>` и выводит
 * поэлементную сумму (элементы разделены пробелом).
 *
 * @return 0 при успешном завершении
 */
int main()
{
    int32_t n_i32 = 0;
    int32_t m_i32 = 0;

    if (std::scanf("%d %d", &n_i32, &m_i32) != 2)
    {
        return 0;
    }

    if (n_i32 <= 0)
    {
        std::putchar('\n');
        return 0;
    }

    const size_t count = static_cast<size_t>(n_i32);

    std::vector<int32_t> a;
    std::vector<int32_t> b;
    a.reserve(count);
    b.reserve(count);

    for (size_t i = 0; i != count; ++i)
    {
        a.push_back(static_cast<int32_t>(i));
    }
    for (size_t i = 0; i != count; ++i)
    {
        b.push_back(static_cast<int32_t>(i));
    }

    for (size_t i = 0; i != count; ++i)
    {
        int32_t sum_i32 = a[i] + b[i];
        std::printf("%d", sum_i32);
        if (i + 1 < count)
        {
            std::putchar(' ');
        }
    }

    std::putchar('\n');

    return 0;
}
