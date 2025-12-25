/************************************************************************
 * @file script3.cpp
 * @brief Текстовый редактор с поддержкой команд add, undo и print.
 * @note Реализовано с использованием std::stack (LIFO адаптер).
 *
 * @version 1.1 (C++20)
 * @date 
 * @copyright Copyright (c) 2025 Oleg Sokolov. All rights reserved
 *************************************************************************/

/********** Core **********/
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <string_view>

/********** Constants **********/
constexpr std::string_view CMD_ADD = "add";
constexpr std::string_view CMD_UNDO = "undo";
constexpr std::string_view CMD_PRINT = "print";
constexpr std::string_view MSG_EMPTY = "empty";

/************ Class Definition ***********/

/**
 * @brief Класс для управления историей текстовых команд на базе стека
 */
class TextEditor
{
  private:
    std::stack<std::string> history; ///< Стек для хранения добавленных строк

  public:
    /**
     * @brief Добавляет строку в стек
     * @param text Строка для добавления
     */
    void add(std::string text)
    {
        history.push(std::move(text));
    }

    /**
     * @brief Отменяет последнее действие (удаляет вершину стека)
     */
    void undo() noexcept
    {
        if (!history.empty())
        {
            history.pop();
        }
    }

    /**
     * @brief Выводит все действия. 
     * @note Так как std::stack не поддерживает итерацию, 
     * элементы копируются в вектор для корректного вывода.
     */
    void print() const
    {
        if (history.empty())
        {
            std::cout << MSG_EMPTY << "\n";
            return;
        }

        // Копируем стек для вывода, так как прямой итерации нет
        auto temp_stack = history;
        std::vector<std::string> elements;
        elements.reserve(temp_stack.size());

        while (!temp_stack.empty())
        {
            elements.push_back(std::move(temp_stack.top()));
            temp_stack.pop();
        }

        // Выводим в обратном порядке (от старых к новым)
        for (auto it = elements.rbegin(); it != elements.rend(); ++it)
        {
            std::cout << *it << (std::next(it) == elements.rend() ? "" : " ");
        }
        std::cout << "\n";
    }
};

/********** Main Function **********/

/**
 * @brief Точка входа в программу
 * @return Код завершения (0 — успешно)
 */
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n_ops{ 0 };
    if (!(std::cin >> n_ops))
        return 0;

    TextEditor editor;

    for (int i = 0; i < n_ops; ++i)
    {
        std::string command;
        if (!(std::cin >> command))
            break;

        if (command == CMD_ADD)
        {
            std::string text;
            std::cin >> text;
            editor.add(std::move(text));
        }
        else if (command == CMD_UNDO)
        {
            editor.undo();
        }
        else if (command == CMD_PRINT)
        {
            editor.print();
        }
    }

    return 0;
}
