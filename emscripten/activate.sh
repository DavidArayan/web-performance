#!/bin/bash

# REFER to documentation
# https://kripken.github.io/emscripten-site/docs/getting_started/downloads.html

cd emsdk
./emsdk install latest
./emsdk activate latest
source ./emsdk_env.sh
cd ../