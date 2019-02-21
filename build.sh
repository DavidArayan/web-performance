#!/bin/sh

echo "Building sserver and emscripten"

sh ./emscripten_build.sh
sh ./sserver_build.sh

echo "Done Building..."
echo "Run emscripten via emscripten_up.sh call"
echo "Run sserver via sserver_up.sh call"