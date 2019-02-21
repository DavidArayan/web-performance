#!/bin/sh

echo "Running emscripten Docker Image - This will compile all our source files"

docker run -dit --name emscripten emscripten:latest

# remove the older source files if any
docker exec -ti emscripten sh -c "rm -rf /usr/src/app/experiments"

# copy all our source files into the container
docker cp experiments emscripten:/usr/src/app/experiments

# execute out ruby compile script which will compile all of our source files
docker exec -ti emscripten sh -c "cd experiments && ruby compile.rb"

# purge our previously compiled sources from the server directory
rm -rf sserver/public/compiled

# copy all compiled sources from within our container into the server directory
docker cp emscripten:/usr/src/app/experiments/compiled sserver/public

# once all done, stop the container
docker stop emscripten
docker rm -v emscripten