/**********************************************************************
 * @file script9.cpp
 * @brief Считать строку слов, разделённых пробелом, и вывести её.
 *
 * @details Программа читает одну строку из стандартного ввода (включая пробелы)
 * и выводит её без изменений.
 *
 * @date 2025-12-01
 * @copyright Copyright (c) 2025
 **********************************************************************/

/********** Core **********/
#include <cstdint>
#include <cstdio>

/********** Main Function **********/
/**
 * @brief Точка входа программы.
 * Читает одну строку (включая пробелы) и выводит её.
 *
 * @return 0 при успешном завершении
 */
int main(void)
{
    // Buffer sized to handle typical input lines;
    static constexpr size_t BUF_SZ = 2048u;
    char buf[BUF_SZ];

    if (std::fgets(buf, static_cast<int>(BUF_SZ), stdin) == nullptr)
    {
        return 0;
    }

    // Remove trailing newline if present
    for (size_t i = 0; i != BUF_SZ; ++i)
    {
        if (buf[i] == '\0')
        {
            break;
        }
        if (buf[i] == '\n')
        {
            buf[i] = '\0';
            break;
        }
    }

    std::printf("%s\n", buf);
    return 0;
}
