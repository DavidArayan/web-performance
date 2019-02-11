#!/bin/bash

# copy all the sources from the original folder
# to the destination (target) folder
find "matrix_c" -name \*.c -exec cp {} "matrix_asm" \;
find "matrix_c" -name \*.h -exec cp {} "matrix_asm" \;

find "matrix_c" -name \*.c -exec cp {} "matrix_wasm" \;
find "matrix_c" -name \*.h -exec cp {} "matrix_wasm" \;