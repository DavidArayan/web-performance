#!/bin/sh

git clone https://github.com/juj/emsdk.git

cd emsdk

./emsdk update
./emsdk install latest
./emsdk activate latest
source ./emsdk_env.sh