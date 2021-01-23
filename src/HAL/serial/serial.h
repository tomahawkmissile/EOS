#ifndef HAL_SERIAL_H
#define HAL_SERIAL_H

#include <stdbool.h>
#include <string.h>

#include "../../core/system.h"

#include "../../core/utils/string/strings.h"

//#ifdef FRONTEND

#if FRONTEND == 1 //If atmega2560
    #include "../frontends/ATMEGA/2560/serial/serial.h"
    #define HAL_serial_init() atmega2560_uart_init()
    #define HAL_serial_putchar(c) atmega2560_uart_putchar(c)
    #define HAL_serial_getchar() atmega2560_uart_getchar()
    #define HAL_serial_available() atmega2560_uart_rxbuffer_ready()
#elif FRONTEND == 2 //If atmega328p
    #include "../frontends/ATMEGA/328p/serial/serial.h"
    #define HAL_serial_init() atmega328p_uart_init()
    #define HAL_serial_putchar(c) atmega328p_uart_putchar(c)
    #define HAL_serial_getchar() atmega328p_uart_getchar()
    #define HAL_serial_available() atmega328p_uart_rxbuffer_ready()
#endif

void HAL_serial_putstring(const char* str);
void serial_println(const char* line);
void serial_print(const char* line);
void serial_printChar(char c);
void serial_linebreak(void);
bool serial_available(void);
char serial_read(void);

//#endif

#endif