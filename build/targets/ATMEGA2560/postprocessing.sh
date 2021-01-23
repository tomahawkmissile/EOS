#!/bin/bash

avr-objcopy -O ihex -j .text -j .data eos.elf eos.hex                                    #   <- use this to turn into hex file
avrdude -V -c wiring -p m2560 -P /dev/ttyACM0 -b 115200 -F -D -U flash:w:eos.hex         #     <- use this to upload