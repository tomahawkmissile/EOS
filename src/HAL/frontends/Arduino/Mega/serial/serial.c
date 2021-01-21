#include <util/setbaud.h>

#define F_CPU 16000000UL
#define BAUD 9600

void ATMEGA2560_UART_INIT(void) {
    UBRR0H = UBRRH_VALUE;
    UBRR0L = UBRRL_VALUE;

    #if USE_2X
    UCSR0A |= _BV(U2X0);
    #else
    UCSR0A &= ~(_BV(U2X0));
    #endif

    UCSR0C = _BV(UCSZ01) | _BV(UCSZ00); //8-bit data
    UCSR0B = _BV(RXEN0) | _BV(TXEN0); //Enable RX and TX
}

void ATMEGA2560_UART_PUTCHAR(char c, FILE* stream) {
    if(c == '\n') {
        ATMEGA2560_UART_PUTCHAR('\r', stream);
    }
    loop_until_bit_is_set(UCSR0A, UDRE0);
    UDR0 = c;
}
char ATMEGA2560_UART_GETCHAR(FILE* stream) {
    loop_until_bit_is_set(UCSR0A, RXC0);
    return UDR0;
}