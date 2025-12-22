/************************************************************************
 * @file script7.cpp
 * @brief Программа для нахождения пересечения двух последовательностей чисел
 * @note Каждое число в результате встречается только один раз.
 * 
 * @version 1.0 (C++20)
 * @date 
 * @copyright Copyright (c) 2025 Oleg Sokolov
 *************************************************************************/

/********** Core **********/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

/********** STL Containers **********/
#include <set>
#include <algorithm>
#include <iterator>

/********** Function Prototypes **********/

/**
 * @brief Считывает строку чисел и преобразует её в упорядоченное множество
 * @param[in] input_line Строка, содержащая числа, разделенные пробелом
 * @return std::set<int> Множество уникальных целых чисел
 **/
[[nodiscard]] std::set<int>
parse_line_to_set(const std::string& input_line);

/********** Main Function **********/

/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 **/
int main()
{
    std::string line1;
    std::string line2;

    // Считываем первую последовательность
    if (!std::getline(std::cin, line1))
    {
        return 0;
    }

    // Считываем вторую последовательность
    if (!std::getline(std::cin, line2))
    {
        // Если второй строки нет, пересечение пустое (согласно Sample 2)
        return 0;
    }

    const std::set<int> set1 = parse_line_to_set(line1);
    const std::set<int> set2 = parse_line_to_set(line2);

    /********** Intersection Logic **********/
    bool is_first = true;

    // Итерируемся по первому множеству и проверяем наличие элемента во втором
    for (const int value : set1)
    {
        if (set2.contains(value))
        {
            if (!is_first)
            {
                std::cout << " ";
            }
            std::cout << value;
            is_first = false;
        }
    }

    std::cout << std::endl;

    return 0;
}

/********** Function Implementation **********/

/**
 * @brief Реализация парсинга строки в std::set
 **/
std::set<int>
parse_line_to_set(const std::string& input_line)
{
    std::set<int> result_set;
    std::stringstream ss(input_line);
    int number{};

    while (ss >> number)
    {
        result_set.insert(number);
    }

    return result_set;
}
