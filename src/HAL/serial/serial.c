#include "serial.h"

void HAL_serial_putstring(const char* str) {
    unsigned int len=strlen(str);
    for(unsigned int i=0;i<len;i++) {
        HAL_serial_putchar((char)str[i]);
    }
}

void serial_println(const char* line) {
    HAL_serial_putstring(concat(line,'\n'));
}
void serial_print(const char* line) {
    HAL_serial_putstring(line);
}
void serial_linebreak(void) {
    HAL_serial_putchar('\n');
}
bool serial_available(void) {
    return HAL_serial_available();
}
char serial_read(void) {
    return HAL_serial_getchar();
}