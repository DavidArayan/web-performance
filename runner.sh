#!/bin/sh

# Set our EMSDK Environment Variables
#source ./../../../emscripten/emsdk/emsdk_env.sh

# run a super-simple HTML server
python -m SimpleHTTPServer 8080
#emrun dct.html --browser chrome