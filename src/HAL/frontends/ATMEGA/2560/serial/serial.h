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

void ATMEGA2560_UART_INIT(void);
void ATMEGA2560_UART_PUTCHAR(char c);
char ATMEGA2560_UART_GETCHAR();
bool ATMEGA2560_UART_RXBUFFER_READY(void);

#endif