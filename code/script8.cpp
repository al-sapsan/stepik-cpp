/************************************************************************
 * @file script8.cpp
 * @brief Поиск карт, встречающихся дважды в обеих колодах
 *
 * @version 1.0
 * @date 2023-10-27
 * @copyright Copyright (c) 2025 Oleg Sokolov
 *************************************************************************/

/********** Core **********/
#include <iostream>
#include <string>
#include <map>
#include <set>

/************ Structure Definition ***********/

/**
 * @brief Структура, представляющая карту
 * * Хранит масть и значение, поддерживает лексикографическое сравнение
 * для корректной сортировки (сначала значение, затем масть).
 */
struct Card
{
    std::string suit;
    int value;

    /**
     * @brief Оператор сравнения для сортировки
     * @param other Другая карта для сравнения
     * @return true если текущая карта меньше по значению или (при равенстве) по масти
     */
    auto operator<(const Card& other) const -> bool
    {
        if (value != other.value)
        {
            return value < other.value;
        }
        return suit < other.suit;
    }
};

/********** Function Prototype **********/

/**
 * @brief Считывает колоду и подсчитывает частоту каждой карты
 * @param count Количество карт для чтения
 * @return Словарь, где ключ — карта, значение — количество вхождений
 */
std::map<Card, int>
read_deck(size_t count);

/********** Main Function **********/

/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 */
int main()
{
    size_t n1{};
    if (!(std::cin >> n1))
        return 0;
    auto deck1 = read_deck(n1);

    size_t n2{};
    if (!(std::cin >> n2))
        return 0;
    auto deck2 = read_deck(n2);

    std::set<Card> result;
    for (const auto& [card, count] : deck1)
    {
        // Условие: как минимум дважды в ПЕРВОЙ и как минимум дважды во ВТОРОЙ
        if (count >= 2)
        {
            if (auto it = deck2.find(card); it != deck2.end() && it->second >= 2)
            {
                result.insert(card);
            }
        }
    }
    for (const auto& card : result)
    {
        std::cout << card.suit << " " << card.value << "\n";
    }
    return 0;
}

/********** Function Implementation **********/

std::map<Card, int>
read_deck(size_t count)
{
    std::map<Card, int> deck_map;
    for (size_t i = 0; i < count; ++i)
    {
        std::string s;
        int v;
        std::cin >> s >> v;
        deck_map[{ s, v }]++;
    }
    return deck_map;
}
