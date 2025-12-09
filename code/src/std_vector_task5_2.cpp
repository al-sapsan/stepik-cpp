/**********************************************************************
 * @file script7.cpp
 * @brief Удаление дубликатов из отсортированного массива, возвращает k — количество уникальных элементов.
 *
 * @details Считывает n и n отсортированных целых чисел, перемещает уникальные
 * элементы в начало массива и выводит количество уникальных элементов k.
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
 * @brief Точка входа.
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
        std::printf("0\n");
        return 0;
    }

    const size_t n_sz = static_cast<size_t>(n_i32);
    std::vector<int32_t> arr_i32(n_sz);

    for (size_t i = 0; i != n_sz; ++i)
    {
        if (std::scanf("%d", &arr_i32[i]) != 1)
        {
            return 0;
        }
    }

    size_t write_idx = 0;
    size_t i = 0;

    while (i != n_sz)
    {
        // Copy unique element
        arr_i32[write_idx] = arr_i32[i];
        ++write_idx;

        // Skip all duplicates of current element
        int32_t current = arr_i32[i];
        while (i != n_sz && arr_i32[i] == current)
        {
            ++i;
        }
    }

    std::printf("%zu\n", write_idx);
    return 0;
}