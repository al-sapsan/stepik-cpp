/**********************************************************************
 * @file script4.cpp
 * @brief Решение задачи Two Sum: найти два индекса i < j, такие что
 *        vec[i] + vec[j] == target.
 *
 * @details Вход: n, затем n целых чисел (элементы вектора), затем целое
 * target. Выход: два индекса i и j (0-based), разделённые пробелом.
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

    if (n_i32 < 2)
    {
        return 0;
    }

    const size_t n_sz = static_cast<size_t>(n_i32);
    std::vector<int32_t> vec_i32;
    vec_i32.resize(n_sz);

    for (size_t i = 0; i != n_sz; ++i)
    {
        std::scanf("%d", &vec_i32[i]);
    }

    int32_t target_i32 = 0;
    if (std::scanf("%d", &target_i32) != 1)
    {
        return 0;
    }

    std::unordered_map<int32_t, size_t> map_val_idx;
    map_val_idx.reserve(n_sz);

    for (size_t i = 0; i != n_sz; ++i)
    {
        const int32_t val_i32 = vec_i32[i];
        const int32_t need_i32 = target_i32 - val_i32;

        auto it = map_val_idx.find(need_i32);
        if (it != map_val_idx.end())
        {
            std::printf("%zu %zu\n", it->second, i);
            return 0;
        }

        // store current value -> index
        map_val_idx.emplace(val_i32, i);
    }

    return 0;
}
