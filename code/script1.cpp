/**********************************************************************
 * @file script1.cpp
 * @brief Симуляция истории браузера с навигацией.
 *
 * @details Программа обрабатывает команды браузера:
 * - visit X: переход на страницу X
 * - back: возврат на предыдущую страницу
 * - forward: переход вперед (если использовался back)
 * - print: вывод текущей страницы
 *
 * @date 2025-01-01
 * @copyright Copyright (c) 2025
 **********************************************************************/

/********** Core **********/
#include <iostream>
#include <sstream>
#include <vector>

/********** Functions Declarations **********/

/**
 * @brief Читает последовательность целых чисел из строки
 * @param input Входная строка с числами, разделенными пробелами
 * @return Вектор целых чисел
 */
std::vector<int> readSequence(const std::string& input);

/**
 * @brief Фильтрует последовательность, удаляя элементы меньше предыдущего
 * @param sequence Исходная последовательность
 * @return Отфильтрованная последовательность
 */
std::vector<int> filterSequence(const std::vector<int>& sequence);

/********** Main Function **********/
/**
 * @brief Точка входа программы.
 * @return 0 при успешном выполнении
 */
int main()
{
    std::string line;
    std::getline(std::cin, line);

    auto sequence = readSequence(line);
    auto filtered = filterSequence(sequence);

    // Выводим результат
    for (size_t i = 0; i < filtered.size(); ++i)
    {
        if (i > 0)
            std::cout << " ";
        std::cout << filtered[i];
    }
    std::cout << " " << '\n';

    return 0;
}

/********** Functions Implementations **********/

// === < Read Function > === //
std::vector<int> readSequence(const std::string& input)
{
    std::vector<int> sequence;
    std::istringstream iss(input);
    int num;

    while (iss >> num)
    {
        sequence.push_back(num);
    }

    return sequence;
}

// === < Filter Function > === //
std::vector<int> filterSequence(const std::vector<int>& sequence)
{
    if (sequence.empty())
        return {};

    std::vector<int> result;
    result.push_back(sequence[0]); // Первый элемент всегда остается

    for (size_t i = 1; i < sequence.size(); ++i)
    {
        if (sequence[i] >= sequence[i - 1])
        {
            result.push_back(sequence[i]);
        }
    }

    return result;
}
