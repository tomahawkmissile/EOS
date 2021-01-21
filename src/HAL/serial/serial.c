#include "serial.h"
#include <stdbool.h>

void serial_init(void) {

    #ifdef FRONTEND_ATMEGA2560
    #include "../frontends/ATMEGA/2560/serial/serial.h"
    ATMEGA2560_UART_INIT();
    #endif

}

void serial_putchar(char c) {

    #ifdef FRONTEND_ATMEGA2560
    #include "../frontends/ATMEGA/2560/serial/serial.h"
    ATMEGA2560_UART_PUTCHAR(c);
    #endif

}
char serial_getchar(void) {

    #ifdef FRONTEND_ATMEGA2560
    #include "../frontends/ATMEGA/2560/serial/serial.h"
    return ATMEGA2560_UART_GETCHAR();
    #endif

}
bool serial_available(void) {
    #ifdef FRONTEND_ATMEGA2560
    #include "../frontends/ATMEGA/2560/serial/serial.h"
    return ATMEGA2560_UART_RXBUFFER_READY();
    #endif
}

void serial_putstring(const char* str) {
    unsigned int len=strlen(str);
    for(unsigned int i=0;i<len;i++) {
        serial_putchar(str[i]);
    }
}