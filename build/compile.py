import os
import sys
import argparse

COMPILER_NAME = 'avr-gcc'
COMPILER_FLAGS = '-mmcu=atmega2560 -Os -Wall -Wno-main -Wundef -pedantic -Werror -Wfatal-errors -Wl,--relax,--gc-sections -g -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -fno-split-wide-types -fno-tree-scev-cprop'
LINKER_NAME = 'avr-ld'
LINKER_FLAGS = '-mmcu=atmega2560'

def get_compile_list(target):
    list_compile_c_files = []

    for file in os.listdir("targets/"):
        if file.endswith(".txt"):
            filename = file.split(".")[0]
            if filename.lower() == target.lower(): #case insensitive
                with open('targets/'+filename+'.txt') as f_list:
                    for line in f_list:
                        list_compile_c_files.append(line.rstrip('\n'))
                    return list_compile_c_files

def convert_c_filename_to_o(c_file_name):
    file_name_raw = c_file_name.split(".")[0]
    return file_name_raw+'.o'

def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--target', type=str, help='select compilation target', required=True)
    args=parser.parse_args()

    compile_list = get_compile_list(args.target)
    if compile_list is None:
        print("No files to be compiled! Check your target platform compilation list!")
        exit(-1)

    #Change directory to src/
    os.chdir('../src/')

    file_names=''
    for file_name in compile_list:
        file_names+=file_name+' '

    os.mkdir('../build/output')
    cmd = (COMPILER_NAME+' '+COMPILER_FLAGS+' '+file_names+' -o '+'../build/output/eos.o')
    print('Compiling with command: '+cmd)
    os.system(cmd)

if __name__ == "__main__":
    main()