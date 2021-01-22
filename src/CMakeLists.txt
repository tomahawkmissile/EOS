cmake_minimum_required(VERSION 3.10)

project(EOS VERSION 1.0)
set(PROJECT_NAME eos)

macro(addsrc file_name)
    set(SRC_LIST ${SRC_LIST} "${file_name} ")
endmacro()

macro(add_eos)
    # Generic HAL platform-independent files
    #
    # Main C file
    addsrc(core/main.c)
    #

    addsrc(HAL/serial/hal_serial.c)
endmacro()

macro(set_constants)
    # CMake configuration
    configure_file(version.h.in version.h)
    #
endmacro()

macro(ATMEGA2560)
    set(FRONTEND 1)

    set(MCU atmega2560)
    set(AVR 1)
    set(F_CPU 16000000UL)
    set(PROG_TYPE avrispmkII)
    set(BAUD 9600)

    set_constants()

    #Fuses go here...
    set(E_FUSE 0xFF)
    set(H_FUSE 0x99)
    set(L_FUSE 0x42)
    set(LOCK_BIT 0xff)

    add_definitions(
        -DF_CPU=${F_CPU}
        -DBAUD=${BAUD}
    )

    find_program(AVR_CC avr-gcc)
    find_program(AVR_CXX avr-g++)
    find_program(AVR_OBJCOPY avr-objcopy)
    find_program(AVR_SIZE_TOOL avr-size)
    find_program(AVR_OBJDUMP avr-objdump)
    find_program(AVR_LINKER avr-ld)

    set(CMAKE_SYSTEM_NAME Generic)
    set(CMAKE_C_COMPILER ${AVR_CC})
    set(CMAKE_CXX_COMPILER ${AVR_CXX})
    set(CMAKE_C_LINK_EXECUTABLE ${AVR_LINKER})
    #set(CMAKE_C_FLAGS -mmcu=${MCU})
    set(CMAKE_EXE_LINKER_FLAGS -mmcu=${MCU})

    add_compile_options(
        -mmcu=${MCU}
        -std=gnu99
        -Os
        -Wall
        -Wno-main
        -Wundef
        -pedantic
        #-Wstrict-prototypes
        -Werror
        -Wfatal-errors
        -Wl,--relax,--gc-sections
        -g
        -gdwarf-2
        -funsigned-char # a few optimizations
        -funsigned-bitfields
        -fpack-struct
        -fshort-enums
        -ffunction-sections
        -fdata-sections
        -fno-split-wide-types
        -fno-tree-scev-cprop
    )

    set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
    set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
    set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
    # not added automatically, since CMAKE_SYSTEM_NAME is "generic"
    set(CMAKE_SYSTEM_INCLUDE_PATH "${CMAKE_FIND_ROOT_PATH}/include")
    set(CMAKE_SYSTEM_LIBRARY_PATH "${CMAKE_FIND_ROOT_PATH}/lib")

    # Add core files first
    add_eos()

    addsrc(HAL/frontends/ATMEGA/2560/serial/serial.c)
    addsrc(HAL/frontends/ATMEGA/2560/delay/delay.c)

    add_executable(${PROJECT_NAME} "${SRC_LIST}")

    #set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME}.elf)

    #add_custom_target(strip ALL avr-strip ${PROJECT_NAME}.elf DEPENDS ${PROJECT_NAME})

    #add_custom_target(hex ALL avr-objcopy -R .eeprom -O ihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex DEPENDS strip)

    #add_custom_target(eeprom avr-objcopy -j .eeprom  --set-section-flags=.eeprom="alloc,load"  --change-section-lma .eeprom=0 -O ihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.eep DEPENDS strip)

    #add_custom_target(upload avrdude  -c ${PROG_TYPE} -p ${MCU} -U flash:w:${PROJECT_NAME}.hex DEPENDS hex)

    #add_custom_target(upload_eeprom avrdude -c ${PROG_TYPE} -p ${MCU}  -U eeprom:w:${PROJECT_NAME}.eep DEPENDS eeprom)

    #add_custom_target(fuses avrdude -c ${PROG_TYPE} -p ${MCU}  -U lfuse:w:${L_FUSE}:m -U hfuse:w:${H_FUSE}:m -U efuse:w:${E_FUSE}:m -U lock:w:${LOCK_BIT}:m )

    #set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES "${PROJECT_NAME}.hex;${PROJECT_NAME}.eeprom;${PROJECT_NAME}.lst")
endmacro()



# HAL files for each target
# For ATMEGA 2560
ATMEGA2560()
#
