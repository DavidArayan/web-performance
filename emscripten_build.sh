#!/bin/sh

echo "Building emscripten Docker Image"

docker build --no-cache emscripten -t emscripten