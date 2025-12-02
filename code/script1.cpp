/**********************************************************************
 * @file script10.cpp
 * @brief Длина последнего слова в строке.
 *
 * @details Считывает одну строку (включая пробелы) и возвращает длину
 * последнего слова — максимальной непрерывной последовательности символов
 * без пробелов. Если слов нет, возвращает 0.
 *
 * @date 2025-12-01
 * @copyright Copyright (c) 2025
 **********************************************************************/

/********** Core **********/
#include <cstdio>

/********** Main Function **********/
/**
 * @brief Точка входа программы.
 *
 * @return 0 при успешном выполнении
 */
int main(void)
{
    static constexpr size_t BUF_SZ = 4096u;
    char buf[BUF_SZ];

    if (std::fgets(buf, static_cast<int>(BUF_SZ), stdin) == nullptr)
    {
        std::printf("0\n");
        return 0;
    }

    /* find length of string */
    size_t len = 0u;
    for (size_t i = 0u; i != BUF_SZ; ++i)
    {
        if (buf[i] == '\0')
        {
            len = i;
            break;
        }
    }

    /* remove trailing newline or spaces */
    size_t idx = (len == 0u) ? 0u : (len - 1u);
    while (len != 0u)
    {
        if (buf[idx] == '\n' || buf[idx] == '\r' || buf[idx] == ' ' || buf[idx] == '\t')
        {
            if (idx == 0u)
            {
                len = 0u;
                break;
            }
            --idx;
            len = idx + 1u;
            continue;
        }
        break;
    }

    /* count last word length */
    size_t last_len = 0u;
    if (len != 0u)
    {
        idx = len - 1u;
        while (true)
        {
            if (buf[idx] == ' ' || buf[idx] == '\t' || buf[idx] == '\n' || buf[idx] == '\r')
            {
                break;
            }
            ++last_len;
            if (idx == 0u)
            {
                break;
            }
            --idx;
        }
    }

    std::printf("%zu\n", last_len);
    return 0;
}
