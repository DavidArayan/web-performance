#!/bin/sh

echo "Removing sserver Docker Image"

docker stop sserver
docker rm sserver
docker rmi sserver:latest