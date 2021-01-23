#ifndef ATMEGA2560_SERIAL_H
#define ATMEGA2560_SERIAL_H

#ifndef F_CPU
#define F_CPU 16000000
#endif
#ifndef BAUD
#define BAUD 9600
#endif

#include <stdbool.h>
#include <stdio.h>
#include <util/setbaud.h>
#include <avr/io.h>

void atmega2560_uart_init(void);
void atmega2560_uart_putchar(char c);
char atmega2560_uart_getchar();
bool atmega2560_uart_rxbuffer_ready(void);

#endif