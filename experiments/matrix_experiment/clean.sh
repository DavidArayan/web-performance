#!/bin/bash

# remove all files with provided extension, leaving only the
# original source files
cd matrix_asm
find . -type f -name '*.o' -delete
find . -type f -name '*.html' -delete
find . -type f -name '*.wasm' -delete
find . -type f -name '*.js' -delete
find . -type f -name '*.mem' -delete
find . -type f -name '*.map' -delete
find . -type f -name '*.h' -delete
find . -type f -name '*.c' -delete
cd ../
rm -rf matrix_asm_build

cd matrix_wasm
find . -type f -name '*.o' -delete
find . -type f -name '*.html' -delete
find . -type f -name '*.wasm' -delete
find . -type f -name '*.js' -delete
find . -type f -name '*.mem' -delete
find . -type f -name '*.map' -delete
find . -type f -name '*.h' -delete
find . -type f -name '*.c' -delete
cd ../
rm -rf matrix_wasm_build

cd matrix_c
find . -type f -name '*.o' -delete
rm -rf matexp
cd ../
rm -rf matrix_c_build