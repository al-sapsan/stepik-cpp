/**********************************************************************
 * @file script1.cpp
 * @brief Решение: заполнить два вектора и вывести их поэлементную сумму.
 *
 * @details Программа читает два целых числа `n` и `m` (гарантируется n == m),
 * заполняет первый вектор числами от 0 до n-1 и второй вектор числами от 0 до m-1,
 * затем вычисляет поэлементную сумму и выводит результат через пробел.
 *
 * @date 2025-11-25
 * @copyright Copyright (c) 2025
 **********************************************************************/

/********** Core **********/
#include <cstdint>
#include <cstdio>
#include <cstdlib>

/********** Main Function **********/ */
    /**
     * @brief Точка входа программы.
     *
     * Читает `n` и `m`, заполняет два массива значениями 0..n-1 и 0..m-1,
     * затем выводит поэлементную сумму.
     *
     * @return 0 — успешное завершение
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

    uint32_t count_u32 = static_cast<uint32_t>(n_i32);

    /* Allocate arrays (C-style) */
    int32_t *arr_a_i32 = static_cast<int32_t *>(std::malloc(static_cast<size_t>(count_u32) * sizeof(int32_t)));
    int32_t *arr_b_i32 = static_cast<int32_t *>(std::malloc(static_cast<size_t>(count_u32) * sizeof(int32_t)));
    if (arr_a_i32 == nullptr || arr_b_i32 == nullptr)
    {
        std::free(arr_a_i32);
        std::free(arr_b_i32);
        return 0;
    }

    for (uint32_t i_u32 = 0; i_u32 < count_u32; ++i_u32)
    {
        arr_a_i32[i_u32] = static_cast<int32_t>(i_u32);
    }
    for (uint32_t i_u32 = 0; i_u32 < count_u32; ++i_u32)
    {
        arr_b_i32[i_u32] = static_cast<int32_t>(i_u32);
    }

    for (uint32_t i_u32 = 0; i_u32 < count_u32; ++i_u32)
    {
        int32_t sum_i32 = arr_a_i32[i_u32] + arr_b_i32[i_u32];
        std::printf("%d", sum_i32);
        if (i_u32 + 1 < count_u32)
        {
            std::putchar(' ');
        }
    }
    std::putchar('\n');

    std::free(arr_a_i32);
    std::free(arr_b_i32);

    return 0;
}
