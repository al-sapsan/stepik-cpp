/**********************************************************************
 * @file script6.cpp
 * @brief Построить массив ans по правилу ans[i] = nums[nums[i]] для нулевой перестановки.
 *
 * @details Считывает n, затем массив nums длины n — перестановку чисел 0..n-1.
 * Формирует и выводит массив ans, где ans[i] = nums[nums[i]]. Элементы
 * выводятся через пробел с завершающим пробелом и переводом строки.
 *
 * @date 2025-11-28
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
 * @return 0 при успешном завершении
 */
int main(void)
{
    int32_t n_i32 = 0;
    if (std::scanf("%d", &n_i32) != 1)
    {
        return 0;
    }

    if (n_i32 <= 0)
    {
        std::putchar('\n');
        return 0;
    }

    const size_t count = static_cast<size_t>(n_i32);

    std::vector<int32_t> nums_i32;
    nums_i32.resize(count);

    // Read with error checking
    for (size_t i = 0; i != count; ++i)
    {
        if (std::scanf("%d", &nums_i32[i]) != 1)
        {
            return 0;
        }
    }

    std::vector<int32_t> ans_i32;
    ans_i32.resize(count);

    // Process with bounds checking
    for (size_t i = 0; i != count; ++i)
    {
        const int32_t idx_i32 = nums_i32[i];
        const size_t idx_sz = static_cast<size_t>(idx_i32);

        // Verify it's a valid permutation index
        if (idx_i32 >= 0 && idx_sz < count)
        {
            ans_i32[i] = nums_i32[idx_sz];
        }
        else
        {
            // Invalid permutation - use sentinel value
            ans_i32[i] = -1;
        }
    }

    // Output results
    for (size_t i = 0; i != count; ++i)
    {
        std::printf("%d ", ans_i32[i]);
    }
    std::putchar('\n');

    return 0;
}