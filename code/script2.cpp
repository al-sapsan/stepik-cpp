/**********************************************************************
 * @file script2.cpp
 * @brief Решение: поэлементная сумма двух векторов, заполненных 0..n-1 и 0..m-1.
 *
 * @details Программа читает два целых числа `n` и `m` (гарантируется n == m),
 * затем выводит поэлементную сумму двух векторов. Для экономии памяти
 * элементы вычисляются на лету (без дополнительного выделения массивов).
 *
 * @date 2025-11-27
 * @copyright Copyright (c) 2025
 **********************************************************************/

/********** Core **********/
#include <cstdint>
#include <cstdio>

/********** Main Function **********/
/**
 * @brief Точка входа программы.
 * @return 0 при успешном завершении
 */
int main(void)
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

    size_t count = static_cast<size_t>(n_i32);

    for (size_t i = 0; i < count; ++i)
    { // Standard loop index
        int32_t sum_i32 = static_cast<int32_t>(i * 2);
        std::printf("%d", sum_i32);
        if (i + 1 < count)
        {
            std::putchar(' ');
        }
    }

    std::putchar('\n');

    return 0;
}
