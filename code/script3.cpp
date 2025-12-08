/**********************************************************************
 * @file script3.cpp
 * @brief Поиск длины самой длинной непрерывной возрастающей последовательности.
 *
 * @details Считывает последовательность целых чисел и находит длину
 * максимальной непрерывной (подряд идущей) возрастающей подпоследовательности.
 * Алгоритм работает за O(N) - один проход по входным данным.
 *
 * @date 2025-01-07
 * @copyright Copyright (c) 2025
 **********************************************************************/

/********** Core **********/
#include <iostream>
#include <vector>
#include <limits>

/********** Main Function **********/
/**
 * @brief Точка входа программы.
 *
 * @return 0 при успешном выполнении
 */
int main(void)
{
    std::vector<long long> nums;
    long long value;


    // Считываем все числа из входного потока
    while (std::cin >> value)
        {
            if (value > std::numeric_limits<long long>::max() - 1000 ||
                value < std::numeric_limits<long long>::min() + 1000)
            {
                std::cerr << "Warning: Value near 64-bit limits: " << value << std::endl;
            }
            nums.push_back(value);
        }

    if (std::cin.fail() && !std::cin.eof())
        {
            std::cin.clear();
            std::string dummy;
            std::cin >> dummy; // Consume invalid input
            std::cerr << "Warning: Skipped invalid input" << std::endl;
        }

        if (nums.empty())
        {
            std::cout << 0 << std::endl;
            return 0;
        }

    // Инициализация переменных для отслеживания длин последовательностей
    size_t max_length = 1;      // Максимальная длина возрастающей последовательности
    size_t current_length = 1;  // Текущая длина возрастающей последовательности

    // Проходим по вектору, начиная со второго элемента
    for (size_t i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > nums[i - 1])
            {
                ++current_length;
                if (current_length > max_length)
                    max_length = current_length;
            }
            else
            {
                current_length = 1;
            }
        }

        std::cout << max_length << std::endl;
        return 0;
    }
