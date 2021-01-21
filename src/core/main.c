#include "../HAL/serial/serial.h"

void loop(){
    serial_putstring("Hello, World!");
}
void setup() {
    serial_init();
}

void main(void) {
    setup();
    loop();
}