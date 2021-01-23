#ifndef ATMEGA2560_DELAY_H
#define ATMEGA2560_DELAY_H

#include "../../../../../core/system.h"

#include <avr/io.h>
#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>

void atmega2560_delay_ms(int ms);

#endif