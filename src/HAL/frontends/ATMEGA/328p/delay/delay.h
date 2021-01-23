#ifndef HAL_ARDUINOMEGA_SERIAL_H
#define HAL_ARDUINOMEGA_SERIAL_H

#include "../../../../../core/system.h"

#include <avr/io.h>
#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>

void ATMEGA2560_DELAY_MS(int ms);

#endif