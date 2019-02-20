#!/bin/sh

echo "Running sserver Docker Image"

docker run -p 8080:8080 -dit --name sserver sserver:latest
docker exec -ti sserver sh -c "http-server ./sserver/public"