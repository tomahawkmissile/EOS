#ifndef ATMEGA328P_SERIAL_H
#define ATMEGA328P_SERIAL_H

#ifndef F_CPU
#define F_CPU 8000000
#endif
#ifndef BAUD
#define BAUD 9600
#endif

#include <stdbool.h>
#include <stdio.h>
#include <util/setbaud.h>
#include <avr/io.h>

void atmega328p_uart_init(void);
void atmega328p_uart_putchar(char c);
char atmega328p_uart_getchar();
bool atmega328p_uart_rxbuffer_ready(void);

#endif