cmake_minimum_required(VERSION 3.10)

project(EOS VERSION 1.0)

# Main C file
add_executable(EOS core/main.c)
#

# HAL files for each target
# ATMEGA 2560
add_executable(EOS HAL/frontends/ATMEGA/2560/serial/serial.c)
add_executable(EOS HAL/frontends/ATMEGA/2560/delay/delay.c)
add_executable(EOS HAL/frontends/ATMEGA/2560/delay/delay.c)
#

# Generic HAL platform-independent files
add_executable(EOS HAL/serial/serial.c)
#

# CMake configuration
configure_file(version.h.in version.h)
target_include_directories(EOS PUBLIC "${PROJECT_BINARY_DIR}")
#