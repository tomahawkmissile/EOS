#include "hal_serial.h"

void HAL_serial_putstring(const char* str) {
    unsigned int len=strlen(str);
    for(unsigned int i=0;i<len;i++) {
        HAL_serial_putchar((char)str[i]);
    }
}