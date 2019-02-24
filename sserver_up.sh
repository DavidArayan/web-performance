#!/bin/sh

echo "Running sserver Docker Image"

# bring down existing container if its running
sh sserver_down.sh

# spin our container up
docker run -p 8080:8080 -dit --name sserver sserver:latest

# delete our old public folder inside the container
docker exec -ti sserver sh -c "rm -rf /usr/src/app/sserver/public"

# copy our current local version into the container
docker cp sserver/public sserver:/usr/src/app/sserver/public

# run our http-server to start serving the files on localhost
docker exec -ti sserver sh -c "http-server ./sserver/public"