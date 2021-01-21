#ifndef HAL_SERIAL_H
#define HAL_SERIAL_H

#include <stdbool.h>

void serial_init(void);
void serial_putchar(char c);
char serial_getchar(void);
bool serial_available(void);
void serial_putstring(const char* str);

#endif