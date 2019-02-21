#!/bin/sh

echo "Nuking sserver and emscripten"

sh ./emscripten_clean.sh
sh ./sserver_clean.sh

echo "Done Nuking... Ensure to rebuild sserver and emscripten"