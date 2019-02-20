#!/bin/sh

echo "Cleaning sserver Docker Image"

docker stop sserver
docker rm -v sserver
docker rmi sserver:latest