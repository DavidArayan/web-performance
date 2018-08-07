#!/bin/sh

# remove all files with provided extension, leaving only the
# original source files
cd delaunay_asm
find . -type f -name '*.o' -delete
find . -type f -name '*.html' -delete
find . -type f -name '*.wasm' -delete
find . -type f -name '*.js' -delete
find . -type f -name '*.mem' -delete
cd ../
rm -rf delaunay_asm_build

cd delaunay_wasm
find . -type f -name '*.o' -delete
find . -type f -name '*.html' -delete
find . -type f -name '*.wasm' -delete
find . -type f -name '*.js' -delete
find . -type f -name '*.mem' -delete
cd ../
rm -rf delaunay_wasm_build