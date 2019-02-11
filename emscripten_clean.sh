#!/bin/sh

echo "Removing emscripten Docker Image"

docker stop emscripten
docker rm -v emscripten
docker rmi emscripten:latest