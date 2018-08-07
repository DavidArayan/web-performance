#!/bin/sh

# set environment variables
source ./../../emscripten/emsdk/emsdk_env.sh

cd delaunay_asm
yes | sudo emmake make dct
cd ../
#cd delaunay_wasm
#yes | sudo emmake make dct
#cd ../