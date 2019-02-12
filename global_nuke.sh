#!/bin/sh

echo "Nuking Everything..."

docker kill $(docker ps -q)

# Delete all containers
docker rm $(docker ps -a -q)

# Delete all images
docker rmi $(docker images -q)
docker volume rm $(docker volume ls -q)

echo "Done Nuking... Ensure to rebuild everything again!"