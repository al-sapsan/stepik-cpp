/**********************************************************************
 * @file script5.cpp
 * @brief Подсчёт "хороших пар" в массиве (nums[i] == nums[j], i < j).
 *
 * @details Считывает n, затем n целых чисел (в диапазоне -10000..10000)
 * и выводит количество пар (i, j), i < j, таких что nums[i] == nums[j].
 *
 * @date 2025-11-28
 * @copyright Copyright (c) 2025
 **********************************************************************/

/********** Core **********/
#include <cstdint>
#include <cstdio>
#include <vector>
#include <unordered_map>

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

    if (n_i32 < 2)
    {
        std::printf("0\n");
        return 0;
    }

    const size_t n_sz = static_cast<size_t>(n_i32);

    // Используем vector для хранения входных данных
    std::vector<int32_t> nums;
    nums.resize(n_sz);

    // Считываем все элементы в vector
    for (size_t i = 0; i != n_sz; ++i)
    {
        if (std::scanf("%d", &nums[i]) != 1)
        {
            return 0;
        }
    }

    // Подсчитываем частоты элементов
    std::unordered_map<int32_t, size_t> counts_map;
    counts_map.reserve(n_sz);

    long long ans_i64 = 0;

    // Обрабатываем все элементы из vector
    for (size_t i = 0; i != n_sz; ++i)
    {
        const int32_t val_i32 = nums[i];

        auto it = counts_map.find(val_i32);
        if (it != counts_map.end())
        {
            // Количество новых пар = текущее количество вхождений этого значения
            ans_i64 += static_cast<long long>(it->second);
            ++(it->second);
        }
        else
        {
            counts_map.emplace(val_i32, 1u);
        }
    }

    std::printf("%lld\n", ans_i64);

    return 0;
}