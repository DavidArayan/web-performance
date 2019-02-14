FROM apiaryio/emcc:1.38.11

WORKDIR /usr/src/app

RUN apt update && \
	yes | apt install ruby-full && \
	ruby --version