#!/bin/sh

# REFER to documentation
# https://kripken.github.io/emscripten-site/docs/getting_started/downloads.html

yes | sudo rm -rf emsdk
yes | sudo git clone https://github.com/juj/emsdk.git
cd emsdk
yes | sudo git pull
yes | sudo python emsdk install latest
yes | sudo python emsdk activate latest
yes | sudo source ./emsdk_env.sh