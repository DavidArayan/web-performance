#!/bin/sh

echo "Removing sserver Docker Image"

docker stop sserver
docker rm -v sserver