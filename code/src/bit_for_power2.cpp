/**********************************************************************
 * @file script4.cpp
 * @brief Формирование массива степеней двойки.
 *
 * @details Программа формирует и выводит целочисленный массив размера 10,
 * содержащий степени двойки от 2^1 до 2^10.
 *
 * @date 2025-01-01
 * @copyright Copyright (c) 2025
 **********************************************************************/

/********** Core **********/
#include <iostream>
#include <array>
#include <cstdint>

/********** Main Function **********/
/**
 * @brief Точка входа программы.
 *
 * @return 0 при успешном выполнении
 */
int main(void)
{
    constexpr size_t N = 10;
    std::array<uint64_t, N> powers_of_two;

    // Заполняем массив: powers_of_two[i] = 2^(i+1)
    uint64_t value = 2;  // 2^1
    for (size_t i = 0; i < N; ++i)
    {
        powers_of_two[i] = value;
        value <<= 1;  // Умножаем на 2 с помощью битового сдвига
    }

    // Выводим результат
    for (size_t i = 0; i < N; ++i)
    {
        std::cout << powers_of_two[i];
        if (i < N - 1)
            std::cout << ' ';
    }
    std::cout << std::endl;
    return 0;
}
