#include "system.h" //This needs to be first!

#include "../HAL/serial/serial.h"

void loop(){
    HAL_serial_putstring("Hello, World!");
}
void setup() {
    HAL_serial_init();
}

void main(void) {
    setup();
    loop();
}