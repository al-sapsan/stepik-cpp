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

/********** Function Declaration **********/
/**
 * @brief Находит позицию для вставки target в отсортированный массив
 * @param nums Отсортированный массив уникальных чисел
 * @param target Искомое число
 * @return Позиция для вставки или индекс найденного элемента
 */
size_t find_insert_position(const std::vector<int32_t> &nums, int32_t target);

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

    const size_t count = static_cast<size_t>(n_i32 > 0 ? n_i32 : 0);

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

    // Call the function and output result
    size_t position = find_insert_position(nums_i32, target_i32);
    std::printf("%zu\n", position);

    return 0;
}

/********** Function Implementation **********/
size_t find_insert_position(const std::vector<int32_t> &nums, int32_t target)
{
    size_t left = 0;
    size_t right = nums.size();

    while (left < right)
    {
        size_t mid = left + (right - left) / 2;

        if (nums[mid] == target)
        {
            return mid; // Exact match found
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    return left; // Insertion position
}
