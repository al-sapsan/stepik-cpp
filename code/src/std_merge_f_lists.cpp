/**********************************************************************
 * @file script5.cpp
 * @brief Объединение двух отсортированных односвязных списков.
 *
 * @details Программа считывает два отсортированных списка в
 * std::forward_list и объединяет их в один отсортированный список
 * с помощью метода merge().
 *
 * @date 2025-01-01
 * @copyright Copyright (c) 2025
 **********************************************************************/

/********** Core **********/
#include <forward_list>
#include <iostream>

/********** Function Declarations **********/
/**
 * @brief Читает отсортированный список из входного потока
 * @param size Количество элементов для чтения
 * @return forward_list с элементами в том же порядке, что и во входных данных
 */
std::forward_list<int> read_sorted_list(int size);

/**
 * @brief Объединяет два отсортированных списка в один отсортированный список
 * @param list1 Первый список
 * @param list2 Второй список
 * @return forward_list с элементами в том же порядке, что и во входных данных
 */
std::forward_list<int> merge_sorted_lists(std::forward_list<int>& list1, std::forward_list<int>& list2);

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

    std::forward_list<int> list1;
    std::forward_list<int>::iterator last_it1;
    bool first1 = true;

    // Читаем первый список
    for (int i = 0; i < n; ++i)
    {
        int value;
        std::cin >> value;

        if (first1)
        {
            list1.push_front(value);
            last_it1 = list1.begin();
            first1 = false;
        }
        else
        {
            last_it1 = list1.insert_after(last_it1, value);
        }
    }

    int m;
    std::cin >> m;

    std::forward_list<int> list2;
    std::forward_list<int>::iterator last_it2;
    bool first2 = true;

    // Читаем второй список
    for (int i = 0; i < m; ++i)
    {
        int value;
        std::cin >> value;

        if (first2)
        {
            list2.push_front(value);
            last_it2 = list2.begin();
            first2 = false;
        }
        else
        {
            last_it2 = list2.insert_after(last_it2, value);
        }
    }

    // Объединяем два отсортированных списка
    list1.merge(list2);

    // Выводим объединённый список
    for (const auto& num : list1)
    {
        std::cout << num << ' ';
    }

    if (n > 0 || m > 0)
    {
        std::cout << '\n';
    }

    return 0;
}

/********** Function Implementations **********/

// === <Read Function> === //
std::forward_list<int> read_sorted_list(int size)
{
    std::forward_list<int> result;

    if (size <= 0)
    {
        return result;
    }

    // Используем before_begin для последовательной вставки
    auto it = result.before_begin();

    for (int i = 0; i < size; ++i)
    {
        int value;
        std::cin >> value;
        it = result.insert_after(it, value);
    }

    return result;
}

// === <Merge Function> === //
std::forward_list<int> merge_sorted_lists(std::forward_list<int>& list1,
                                          std::forward_list<int>& list2)
{
    std::forward_list<int> merged;
    auto it = merged.before_begin();

    auto it1 = list1.begin();
    auto it2 = list2.begin();

    // Пока есть элементы в обоих списках
    while (it1 != list1.end() && it2 != list2.end())
    {
        if (*it1 <= *it2)
        {
            it = merged.insert_after(it, *it1);
            ++it1;
        }
        else
        {
            it = merged.insert_after(it, *it2);
            ++it2;
        }
    }

    // Добавляем оставшиеся элементы из первого списка
    while (it1 != list1.end())
    {
        it = merged.insert_after(it, *it1);
        ++it1;
    }

    // Добавляем оставшиеся элементы из второго списка
    while (it2 != list2.end())
    {
        it = merged.insert_after(it, *it2);
        ++it2;
    }

    return merged;
}
