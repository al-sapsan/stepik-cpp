/**********************************************************************
 * @file script3.cpp
 * @brief Преобразование двоичного числа в десятичное.
 *
 * @details Программа считывает последовательность битов (0 или 1),
 * хранит их в std::forward_list и преобразует двоичное число
 * в десятичное. Самый значимый бит (MSB) находится в начале списка.
 *
 * @date 2025-01-01
 * @copyright Copyright (c) 2025
 **********************************************************************/

/********** Core **********/
#include <forward_list>
#include <iostream>

/********** Main Function **********/
/**
 * @brief Точка входа программы.
 *
 * @return 0 при успешном выполнении
 */
int main(void)
{
    int n;
    std::cin >> n;

    // Обработка случая пустого списка
    if (n == 0)
    {
        std::cout << 0 << '\n';
        return 0;
    }

    std::forward_list<int> bits;
    std::forward_list<int>::iterator last_it;
    bool first = true;

    // Читаем биты и добавляем в конец списка
    for (int i = 0; i < n; ++i)
    {
        int bit;
        std::cin >> bit;

        if (first)
        {
            bits.push_front(bit);
            last_it = bits.begin();
            first = false;
        }
        else
        {
            last_it = bits.insert_after(last_it, bit);
        }
    }

    // Преобразуем двоичное число в десятичное
    // Используем формулу: result = result * 2 + bit
    long long decimal = 0;
    for (const auto& bit : bits)
    {
        decimal = decimal * 2 + bit;
    }

    std::cout << decimal << '\n';

    return 0;
}
