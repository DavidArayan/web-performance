#!/bin/sh

# REFER to documentation
# https://kripken.github.io/emscripten-site/docs/getting_started/downloads.html

git clone https://github.com/juj/emsdk.git

cd emsdk

./emsdk update
./emsdk install latest
./emsdk activate latest
source ./emsdk_env.sh