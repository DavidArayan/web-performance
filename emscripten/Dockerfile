FROM apiaryio/emcc:1.38.11

WORKDIR /usr/src/app

RUN apt update

# Ruby will be used for some internal scripts
RUN yes | apt install ruby-full
RUN ruby --version