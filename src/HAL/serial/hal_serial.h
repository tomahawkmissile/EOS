#ifndef HAL_SERIAL_H
#define HAL_SERIAL_H

#include <stdbool.h>
#include <string.h>

#include "../../../build/version.h"

//#ifdef FRONTEND

#if FRONTEND == 1 //If ATMEGA2560
    #include "../frontends/ATMEGA/2560/serial/serial.h"
    #define HAL_serial_init() ATMEGA2560_UART_INIT()
    #define HAL_serial_putchar(c) ATMEGA2560_UART_PUTCHAR(c)
    #define HAL_serial_getchar() return ATMEGA2560_UART_GETCHAR()
    #define HAL_serial_available() return ATMEGA2560_UART_RXBUFFER_READY()
#endif

void HAL_serial_putstring(const char* str);

//#endif

#endif