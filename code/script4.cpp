/************************************************************************
 * @file script4.cpp
 * @brief Программа для подсчета уникальных чисел в последовательности
 * @note Использует std::unordered_set для обеспечения сложности O(N).
 * @warning Входные данные должны быть разделены пробельными символами.
 *
 * @version 1.0 (C++20)
 * @date 
 * @copyright Copyright (c) 2025
 *************************************************************************/

/********** Core **********/
#include <iostream>
#include <sstream>
#include <string>

/********** Containers **********/
#include <unordered_set>

/********** Function Prototypes **********/
/**
 * @brief Считывает последовательность и вычисляет количество уникальных чисел
 * Функция считывает строку, парсит её в целые числа и использует
 * хеш-таблицу для фильтрации дубликатов.
 * @return size_t Количество уникальных элементов
 **/
size_t count_unique_numbers();

/********** Main Function **********/

/**
 * @brief Точка входа в программу
 * * @return Код завершения (0 — успешно)
 **/
int main()
{
    // Вывод результата работы функции в стандартный поток
    std::cout << count_unique_numbers() << std::endl;

    return 0;
}

/********** Function Implementation **********/
/**
 * @brief Реализация подсчета уникальных чисел
 * * @return size_t Количество различных элементов
 */
size_t count_unique_numbers()
{
    std::string line;

    // Считываем всю строку входных данных
    if (!std::getline(std::cin, line) || line.empty())
    {
        return 0;
    }

    // std::unordered_set хранит только уникальные ключи.
    // Вставка дубликата не увеличивает размер контейнера.
    std::unordered_set<int> unique_elements;

    // Используем строковый поток для удобного извлечения чисел
    std::stringstream ss(line);
    int current_val;

    // Цикл извлечения чисел из потока до конца строки
    while (ss >> current_val)
    {
        unique_elements.insert(current_val);
    }

    // Размер множества равен количеству уникальных чисел
    return unique_elements.size();
}
