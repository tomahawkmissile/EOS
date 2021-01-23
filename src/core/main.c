#include "system.h" //This needs to be first!

#include "../HAL/serial/serial.h"

#include "cli.h"

void loop() {
    cli_run();
}
void setup() {
    HAL_serial_init();

    cli_init();
}

void main(void) {
    setup();
    while(1) loop();
}