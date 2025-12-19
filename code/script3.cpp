/**********************************************************************
 * @file word_analyzer.cpp
 * @brief Инструмент для анализа частоты слов с сохранением порядка появления.
 *
 * Поддерживаемые платформы: ARM Cortex-M, RISC-V, Xtensa (ESP32), RP2040
 *
 * @version 3.4
 * @date 2025-12-19
 *
 * @copyright Copyright (c) 2025
 **********************************************************************/

/********** Core **********/
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

/************ Class Prototypes ***********/

// == < Class TextFrequencyAnalyzer > == //
/**
 * @brief Класс для анализа текста и подсчета частоты слов.
 *
 * Сохраняет порядок первого появления слов для корректного вывода отчета.
 */
class TextFrequencyAnalyzer
{
  private:
    /** @brief Список слов в порядке их первого появления в тексте */
    std::vector<std::string> m_insertion_order_arr;

    /** @brief Хеш-карта для хранения частоты встречаемости слов */
    std::unordered_map<std::string, size_t> m_frequency_map;

  public:
    /**
     * @brief Конструктор по умолчанию.
     */
    TextFrequencyAnalyzer() = default;

    /**
     * @brief Обрабатывает поток ввода и анализирует слова.
     * @param[in] ref_input_stream Ссылка на поток ввода.
     */
    void ProcessStream(std::istream& ref_input_stream)
    {
        std::string current_word;

        // Считываем слова, разделенные пробелами
        while (ref_input_stream >> current_word)
        {
            this->AddWord(current_word);
        }
    }

    /**
     * @brief Выводит отчет о частоте слов в консоль.
     */
    void PrintReport() const
    {
        // Используем size_t для индексации вектора согласно конвенции
        for (size_t i = 0; i < m_insertion_order_arr.size(); ++i)
        {
            const std::string& ref_word = m_insertion_order_arr[i];

            // Получаем частоту из карты. Использование .at() гарантирует const-safety.
            size_t count = m_frequency_map.at(ref_word);

            std::cout << ref_word << " " << count << "\n";
        }
    }

  private:
    /**
     * @brief Добавляет слово в структуры данных.
     * @param[in] ref_word Строка с новым словом.
     */
    void AddWord(const std::string& ref_word)
    {
        // Проверяем, встречалось ли слово ранее
        if (m_frequency_map.find(ref_word) == m_frequency_map.end())
        {
            // Новое слово: запоминаем порядок появления
            m_insertion_order_arr.push_back(ref_word);
            m_frequency_map[ref_word] = 1;
        }
        else
        {
            // Существующее слово: инкрементируем счетчик
            m_frequency_map[ref_word]++;
        }
    }
};

/********** Main Function **********/
/**
 * @brief Точка входа в программу.
 * @return Код завершения (0 — успешно).
 */
int main(void)
{
    // Оптимизация стандартных потоков ввода-вывода
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    TextFrequencyAnalyzer analyzer;

    // 1. Сбор и обработка данных
    analyzer.ProcessStream(std::cin);

    // 2. Вывод результатов в требуемом формате
    analyzer.PrintReport();

    return 0;
}
