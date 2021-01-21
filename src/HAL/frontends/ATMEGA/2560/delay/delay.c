#include <avr/io.h>
#include <util/delay.h>

void ATMEGA2560_DELAY_MS(float ms) {
    _delay_ms((double)ms);
}
void ATMEGA2560_DELAY_US(float us) {
    _delay_us((double)us);
}