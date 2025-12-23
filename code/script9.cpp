/************************************************************************
 * @file script9.cpp
 * @brief Анализатор журнала посещений сайта (подсчет уникальных страниц)
 * @note Программа использует std::set для фильтрации дубликатов страниц
 * и std::map для хранения данных пользователей.
 *
 * @version 1.0
 * @date 
 * @copyright Copyright (c) 2025 Oleg Sokolov
 *************************************************************************/

/********** Core **********/
#include <iostream>
#include <string>

/********** STL **********/
#include <map>
#include <set>

/********** Typedefs **********/
typedef uint32_t u32_t;
typedef std::string str_t;

/********** Main Function **********/
int main(void)
{
    /** Отключаем синхронизацию для ускорения ввода-вывода **/
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    u32_t record_count;
    if (!(std::cin >> record_count))
    {
        return 0;
    }

    /** * Хранилище: ID пользователя -> Множество уникальных страниц.
     * std::map автоматически сортирует ключи (ID) по возрастанию.
     * std::set гарантирует уникальность названий страниц.
     */
    std::map<u32_t, std::set<str_t>> user_history;
    for (size_t i = 0; i < record_count; ++i)
    {
        u32_t user_id;
        str_t page_name;

        if (std::cin >> user_id >> page_name)
        {
            /** * Если ключа user_id нет в map, он будет создан.
             * Затем в set этого пользователя вставляется название страницы.
             */
            user_history[user_id].insert(page_name);
        }
    }

    size_t max_unique_count = 0;
    /** Находим максимальное количество уникальных страниц среди всех пользователей */
    for (const auto& [id, pages] : user_history)
    {
        if (pages.size() > max_unique_count)
        {
            max_unique_count = pages.size();
        }
    }

    /** * Итерируемся по map. Так как map отсортирован по ID, 
     * вывод будет соответствовать условию задачи (по возрастанию ID).
     */
    for (const auto& [id, pages] : user_history)
    {
        if (pages.size() == max_unique_count)
        {
            std::cout << id << "\n";
        }
    }

    return 0;
}
