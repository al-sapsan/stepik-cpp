/**********************************************************************
 * @file script4.cpp
 * @brief Подсчёт драгоценных камней среди имеющихся камней.
 *
 * @details Считывает две строки: jewels (драгоценные камни) и stones
 * (имеющиеся камни). Определяет, сколько символов в stones встречаются
 * среди jewels. Регистр символов имеет значение (case-sensitive).
 *
 * @date 2025-01-07
 * @copyright Copyright (c) 2025
 **********************************************************************/

/********** Core **********/
#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_set>

/********** Data Types **********/
typedef uint32_t u32_t;  ///< Unsigned 32-bit integer
typedef size_t sz_t;     ///< Size type

/********** Function Prototypes **********/
/**
 * @brief Подсчитывает количество драгоценных камней.
 *
 * @details Определяет, сколько символов из stones являются драгоценными
 * камнями (встречаются в jewels). Регистр символов учитывается.
 *
 * @param[in] ref_jewels Ссылка на строку с символами драгоценных камней
 * @param[in] ref_stones Ссылка на строку с имеющимися камнями
 * @return u32_t Количество драгоценных камней в stones
 *
 * @note Функции не модифицируют входные строки
 */
u32_t count_jewels_in_stones(const std::string &ref_jewels, const std::string &ref_stones);

/********** Main Function **********/
/**
 * @brief Точка входа программы.
 *
 * @return 0 при успешном выполнении
 */
int main(void)
{
    std::string jewels;
    std::string stones;

    // Чтение строки с драгоценными камнями
    if (!std::getline(std::cin, jewels))
    {
        std::cout << "0" << std::endl;
        return 0;
    }

    // Чтение строки с имеющимися камнями
    if (!std::getline(std::cin, stones))
    {
        std::cout << "0" << std::endl;
        return 0;
    }

    // Подсчёт драгоценных камней
    u32_t count_u32 = count_jewels_in_stones(jewels, stones);

    // Вывод результата
    std::cout << count_u32 << std::endl;

    return 0;
}

/********** Function Implementation **********/
u32_t count_jewels_in_stones(const std::string &ref_jewels, const std::string &ref_stones)
{
    // Создаём хеш-множество для быстрого поиска O(1)
    std::unordered_set<char> jewels_set;

    // Заполняем множество символами из jewels
    for (sz_t i = 0u; i != ref_jewels.length(); ++i)
    {
        jewels_set.insert(ref_jewels[i]);
    }

    u32_t count_u32 = 0u;

    // Подсчитываем драгоценные камни в stones
    for (sz_t i = 0u; i != ref_stones.length(); ++i)
    {
        // Проверяем, является ли символ драгоценным камнем
        if (jewels_set.find(ref_stones[i]) != jewels_set.end())
        {
            ++count_u32;
        }
    }

    return count_u32;
}
