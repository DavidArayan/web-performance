#!/bin/bash

# copy all the sources from the original folder
# to the destination (target) folder
find "delaunay_original" -name \*.c -exec cp {} "delaunay_asm" \;
find "delaunay_original" -name \*.h -exec cp {} "delaunay_asm" \;

find "delaunay_original" -name \*.c -exec cp {} "delaunay_wasm" \;
find "delaunay_original" -name \*.h -exec cp {} "delaunay_wasm" \;