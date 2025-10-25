/**
 * @file emb_style_c.h
 * @brief Embedded C coding style for robotics and real-time systems
 * @version 3.3
 * @date 2025-07-07
 *
 * @copyright Copyright (c) 2025
 */

#ifndef STYLE_H
#define STYLE_H

#ifdef __cplusplus
extern "C"
{
#endif
    //==============================================================================
    // 📘 Структура кода
    //==============================================================================

    /**
     * 1. Общие сведения (имя файла, назначение, платформа, версия, дата)
     Пример:
        * @file motor_control.c
        * @brief Драйвер управления двигателями (ПИД-регулятор)
        * @version 1.1 (STM32F4xx HAL)
         * @date 2023-08-15
        *
        * @warning Не использовать с DMA без проверки буферов!
        * @note Максимальная частота обновления - 1 кГц

     * 2. Используемые библиотеки (группировать по назначению)
    Пример:
        // === Core ===
        #include <stdint.h>
        #include "stm32f4xx_hal.h"

        // === Drivers ===
        #include "encoder.h"
        #include "pwm.h"

        // === RTOS ===
        #include "FreeRTOS.h"
        #include "task.h"

     * 3. Типы данных
    Пример:
        * typedef int16_t i16_t;
        * typedef uint32_t u32_t;
     * 4. Константы
    Пример:
        * constexpr u16_t MAX_BUFFER_SIZE = 128;
        * constexpr u32_t TIMEOUT_MS_DEFAULT = 1000;
        * constexpr f32_t PI_CONST = 3.1415926f;
     * 5. Прототипы функций с doxygen комментариями
    Пример:
        * @brief Инициализация ПИД-регулятора
        * @param pid Указатель на структуру (должен быть валидным)
        * @param kp Коэффициент пропорциональный [0.0 - 5.0]
        * @return HAL_StatusTypeDef Статус инициализации
        HAL_StatusTypeDef pid_init(pid_controller_t* pid, float kp);

     * 6. Главная функция
     * 7. Реализация функций
     *
     * Указанные заголовки выводятся в следующей нотации
     * Пример:
     * /*** Текст заголовка ***/

    //==============================================================================
    // 📚 Doxygen документация
    //==============================================================================

    /**
     * @brief Краткое описание модуля/функции
     *
     * Подробное описание функциональности. Пример:
     * @code
     * sensor_init(&sensor_cfg);
     * @endcode
     *
     * @param[in] param1 Описание входного параметра
     * @param[out] param2 Описание выходного параметра
     * @return err_code_t Код ошибки (см. err_code_t)
     *
     * @note Важные замечания по использованию
     * @warning Предупреждения о безопасности
     * @see Другие связанные функции
     */

    //==============================================================================
    // 🧱 Variable Naming Conventions
    //==============================================================================

    /*
     * Format:
     * [scope][description]_[type][unit]
     *
     * Scope prefixes:
     *   g_      -> global
     *   s_      -> static (module-local)
     *   m_      -> member (struct/class)
     *   ptr_    -> pointer
     *   vptr_   -> volatile pointer
     *   ref_    -> reference (C++)
     *   arr_    -> array (C++)
     *
     * Type suffixes:
     *   _u8     -> uint8_t
     *   _i8     -> int8_t
     *   _u16    -> uint16_t
     *   _i16    -> int16_t
     *   _u32    -> uint32_t
     *   _i32    -> int32_t
     *   _f32    -> float
     *   _f64    -> double
     *   _b      -> bool
     *
     *   _vu8    -> volatile u8_t
     *   _vu16   -> volatile u16_t
     *   _vu32   -> volatile u32_t
     *   _au32   -> atomic_uint
     */
    // Example:
    volatile u32_t g_system_ticks_vu32 = 0; // Volatile global (e.g., SysTick counter)
    f32_t g_battery_voltage_f32;            // Global float (accessible across modules)
    static i16_t s_error_count_i16 = 0;     // Static (file-scoped) counter
    u8_t *ptr_buffer_u8;                    // Pointer to uint8_t buffer
    pid_params_t *ptr_pid;                  // Pointer to PID struct
    volatile i16_t *vptr_sensor_data_i16;   // Pointer to volatile sensor data
    u16_t (*ptr_arr_matrix_u16)[4];         // Pointer to 4-element array of u16_t
    f32_t &ref_offset_f32 = 1.25f;          // Reference parameter
    f32_t arr_waypoints_f32[10];            // Array of waypoint coordinates

    /** Loop variables:
     *  i, j, k  -> simple loops
     *  row, col -> matrix/array loops
     *  full names -> other cases
     */
    // Example:
    for (u8_t i_u8 = 0; i_u8 < 10; i_u8++)
    { // Standard loop index
        arr_waypoints_f32[i_u8] = 0.0f;
    }

    for (u8_t row_u8 = 0; row_u8 < 4; row_u8++)
    { // Multi-Dimensional Loops
        for (u8_t col_u8 = 0; col_u8 < 4; col_u8++)
        {
            matrix[row_u8][col_u8] = 0;
        }
    }

    //==============================================================================
    // 🧩 Типы данных и периферия
    //==============================================================================

#include <stdint.h>
#include <stdbool.h>
#include <stdatomic.h>

    // Базовые типы
    typedef uint8_t u8_t;   ///< Unsigned 8-bit integer   [0, 255]
    typedef int8_t i8_t;    ///< Signed 8-bit integer     [-128, 127]
    typedef uint16_t u16_t; ///< Unsigned 16-bit integer  [0, 65_535]
    typedef int16_t i16_t;  ///< Signed 16-bit integer    [-32_768, 32_767]
    typedef uint32_t u32_t; ///< Unsigned 32-bit integer  [0, 4_294_967_295]
    typedef int32_t i32_t;  ///< Signed 32-bit integer    [-2_147_483_648, 2_147_483_647]
    typedef float f32_t;    ///< 32-bit float             [~±1.18e−38, ±3.4e+38] (approx)
    typedef double f64_t;   ///< 64-bit double            [~±2.23e−308, ±1.79e+308] (approx)
    typedef bool b_t;       ///< Boolean                  [false, true]

    // Периферия и регистры
    typedef volatile u8_t vu8_t;   ///< Volatile 8-bit
    typedef volatile u16_t vu16_t; ///< Volatile 16-bit
    typedef volatile u32_t vu32_t; ///< Volatile 32-bit
    typedef atomic_uint au32_t;    ///< Atomic 32-bit

    // Битовые поля регистров
    typedef union
    {
        u32_t word;
        struct
        {
            u32_t enable : 1;
            u32_t mode : 2;
            u32_t : 5; // Reserved
        } bits;
    } ctrl_reg_t;

    //==============================================================================
    // 🤖 Робототехника: типы и константы
    //==============================================================================

    // Координаты и движение
    typedef struct
    {
        f32_t x_mm;      ///< Позиция по X (мм)
        f32_t y_mm;      ///< Позиция по Y (мм)
        f32_t theta_rad; ///< Угол (рад)
    } pose2d_t;

    /// Параметры PID регулятора
    typedef struct
    {
        f32_t kp;             ///< Пропорциональный коэффициент
        f32_t ki;             ///< Интегральный коэффициент
        f32_t kd;             ///< Дифференциальный коэффициент
        f32_t integral_limit; ///< Лимит интегратора
    } pid_params_t;

    // Константы
    static const f32_t WHEEL_DIAMETER_MM = 65.0f;     ///< Диаметр колеса
    static const f32_t ENCODER_PPR = 1024.0f;         ///< Импульсов на оборот
    static const f32_t ROBOT_MAX_SPEED_MMPS = 500.0f; ///< Макс. скорость (мм/с)

//==============================================================================
// 🛡 Безопасность и проверки
//==============================================================================

// Проверка указателя
#define CHECK_NULL(ptr)          \
    do                           \
    {                            \
        if (!(ptr))              \
            return ERR_NULL_PTR; \
    } while (0)

// Проверка выравнивания
#define CHECK_ALIGN(ptr, align)         \
    do                                  \
    {                                   \
        if ((uintptr_t)(ptr) % (align)) \
            return ERR_ALIGN;           \
    } while (0)

// Безопасный доступ к volatile
#define VOL_ACCESS(addr) (*(volatile typeof(addr) *)&(addr))

// Ограничение значения
#define CLAMP(val, min, max) \
    ((val) < (min) ? (min) : ((val) > (max) ? (max) : (val)))

    //==============================================================================
    // ⏱ RTOS и задачи
    //==============================================================================

    /// Приоритеты задач FreeRTOS
    typedef enum
    {
        TASK_PRIO_IDLE = 0,   ///< Фоновая задача
        TASK_PRIO_LOW = 1,    ///< Низкий приоритет
        TASK_PRIO_NORMAL = 3, ///< Средний приоритет
        TASK_PRIO_HIGH = 5,   ///< Высокий приоритет
    } task_prio_t;

    /// Шаблон задачи RTOS
    void task_template(void *params)
    {
        // 1. Инициализация
        (void)params; // Подавление предупреждений

        // 2. Основной цикл
        for (;;)
        {
            // Логика задачи
            vTaskDelay(pdMS_TO_TICKS(10));
        }

        // 3. Завершение (не должно достигаться)
        vTaskDelete(NULL);
    }

    //==============================================================================
    // ⚠ Обработка ошибок
    //==============================================================================

    /// Коды ошибок
    typedef enum
    {
        ERR_OK = 0,      ///< Успех
        ERR_INVALID_ARG, ///< Неверный аргумент
        ERR_TIMEOUT,     ///< Таймаут операции
        ERR_HW_FAULT,    ///< Аппаратная ошибка
        ERR_BUSY,        ///< Ресурс занят
        ERR_NOT_INIT     ///< Модуль не инициализирован
    } err_code_t;

/// Макрос обработки ошибок
#define RETURN_IF_ERR(expr)        \
    do                             \
    {                              \
        err_code_t __err = (expr); \
        if (__err != ERR_OK)       \
            return __err;          \
    } while (0)

//==============================================================================
// 🚨 Прерывания (ISR)
//==============================================================================

// Атрибуты для разных компиляторов
#ifdef __GNUC__
#define ISR_ATTR __attribute__((interrupt))
#else
#define ISR_ATTR
#endif

    /// Шаблон обработчика прерывания
    void TIM2_IRQHandler(void) ISR_ATTR
    {
        // 1. Проверка источника
        // 2. Очистка флагов
        // 3. Минимальная обработка
        // 4. Выход
    }

    //==============================================================================
    // 📊 Пример использования
    //==============================================================================

    /**
     * @brief Инициализация двигателя
     * @param[in] cfg Конфигурация двигателя
     * @param[out] handle Указатель на handle
     * @return err_code_t Результат инициализации
     *
     * @warning Не вызывать до инициализации PWM!
     */
    err_code_t motor_init(const motor_cfg_t *cfg, motor_handle_t *handle)
    {
        CHECK_NULL(cfg);
        CHECK_NULL(handle);

        // ... реализация ...

        return ERR_OK;
    }

#ifdef __cplusplus
}
#endif

#endif /* STYLE_H */