#!/bin/sh

echo "Running emscripten Docker Image"

docker run -dit --name emscripten emscripten:latest

# remove the older source files if any
docker exec -ti emscripten sh -c "rm -rf /usr/src/app/experiments"

# copy all our source files into the container
docker cp experiments emscripten:/usr/src/app/experiments

docker exec -ti emscripten sh -c "cd experiments && ruby compile.rb"

rm -rf sserver/public/compiled

docker cp emscripten:/usr/src/app/experiments/compiled sserver/public

# once all done, stop the container
docker stop emscripten
docker rm -v emscripten