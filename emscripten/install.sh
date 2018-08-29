#!/bin/bash

# REFER to documentation
# https://kripken.github.io/emscripten-site/docs/getting_started/downloads.html

rm --recursive -f emsdk
git clone https://github.com/juj/emsdk.git
chmod 777 emsdk
cd emsdk
git pull
./emsdk install latest
./emsdk activate latest
source ./emsdk_env.sh