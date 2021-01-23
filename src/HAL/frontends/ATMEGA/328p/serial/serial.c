#include "serial.h"

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

void ATMEGA2560_UART_PUTCHAR(char c) {
    if(c == '\n') {
        ATMEGA2560_UART_PUTCHAR('\r');
    }
    loop_until_bit_is_set(UCSR0A, UDRE0);
    UDR0 = c;
}
char ATMEGA2560_UART_GETCHAR() {
    loop_until_bit_is_set(UCSR0A, RXC0);
    return UDR0;
}
bool ATMEGA2560_UART_RXBUFFER_READY(void) {
    if(bit_is_set(UCSR0B,RXC0)) {
        return true;
    } else {
        return false;
    }
}