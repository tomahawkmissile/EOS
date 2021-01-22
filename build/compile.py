import os
import sys
import argparse
from pathlib import Path

COMPILER_NAME = 'avr-gcc'
COMPILER_FLAGS = '-mmcu=atmega2560 -Os -DF_CPU=16000000UL -Wall -Wno-main -Wundef -pedantic -Werror -Wfatal-errors -Wl,--relax,--gc-sections -g -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -fno-split-wide-types -fno-tree-scev-cprop'
LINKER_NAME = 'avr-gcc'
LINKER_FLAGS = '-mmcu=atmega2560'

def get_compile_list(target):
    list_compile_c_files = []

    for file in os.listdir("targets/"):
        if file.endswith(".txt"):
            filename = file.split(".")[0]
            if filename.lower() == target.lower(): #case insensitive
                with open('targets/'+filename+'.txt') as f_list:
                    for line in f_list:
                        if not line.startswith('#') and not line.isspace():
                            list_compile_c_files.append(line.rstrip('\n'))
                    return list_compile_c_files

def convert_c_filename_to_o(c_file_name):
    file_name_raw = c_file_name.split(".")[0]
    return file_name_raw+'.o'
def convert_path_to_filename(path_file):
    return path_file.split('/')[-1]
def mkdir_for_output_file(file_name):
    arr=file_name.split('/')
    directory=''
    for i in range(0,len(arr)-1): #assumes working directory is src/. If changed to build/, make start index 2
        directory+=arr[i]+'/'
    Path(directory).mkdir(parents=True, exist_ok=True)

def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--target', type=str, help='select compilation target', required=True)
    args=parser.parse_args()

    compile_list = get_compile_list(args.target)
    if compile_list is None:
        print("No files to be compiled! Check your target platform compilation list!")
        exit(-1)

    if not os.path.exists('output/'):
        os.mkdir('output/')

    #Change directory to src/
    os.chdir('../src/')

    executable_list_string = ''
    for file_name in compile_list:
        executable_location = '../build/output/'+file_name+'.o'
        mkdir_for_output_file(executable_location)
        executable_list_string += executable_location+' '
        cmd = (COMPILER_NAME+' '+COMPILER_FLAGS+' -c -o '+executable_location+' '+file_name)
        print('Compiling with command: '+cmd)
        os.system(cmd)

    binary_location = '../build/output/eos.elf'
    link = (LINKER_NAME+' '+LINKER_FLAGS+' -o '+binary_location+' '+executable_list_string)    
    print('Linking with command: '+link)
    os.system(link)

if __name__ == "__main__":
    main()