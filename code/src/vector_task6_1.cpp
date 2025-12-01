/**********************************************************************
 * @file script8.cpp
 * @brief Поиск индекса target в отсортированном уникальном массиве или места для вставки.
 *
 * @details Считывает n, затем n уникальных отсортированных целых чисел nums,
 * затем число target. Выводит индекс найденного элемента или позицию,
 * куда его следует вставить, чтобы сохранить порядок.
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
    if (std::scanf("%d", &n_i32) != 1 || n_i32 < 0)
    {
        return 0;
    }

    const size_t count = static_cast<size_t>(n_i32);

    // Handle empty array case
    if (count == 0)
    {
        std::printf("0\n");
        return 0;
    }

    std::vector<int32_t> nums_i32;
    nums_i32.resize(count);

    for (size_t i = 0; i != count; ++i)
    {
        if (std::scanf("%d", &nums_i32[i]) != 1)
        {
            return 0;
        }
    }

    int32_t target_i32 = 0;
    if (std::scanf("%d", &target_i32) != 1)
    {
        return 0;
    }

    // Binary search for lower bound (first position where element >= target)
    size_t low = 0;
    size_t high = count;

    while (low != high)
    {
        // Prevent overflow and use bit shift for division by 2
        size_t mid = low + ((high - low) >> 1);

        if (nums_i32[mid] < target_i32)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    // 'low' is the insertion position (also the found index if element exists)
    std::printf("%zu\n", low);

    return 0;
}