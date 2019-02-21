FROM node:11.9.0-alpine

WORKDIR /usr/src/app

# This is the port that our sample server will be running on
ENV EXPOSED_PORT 8080

# Grab http-server to serve our simple HTML files
RUN npm install http-server -g && \
	mkdir -p /usr/src/app/sserver/public

# Copy all our files into the public directory which will be used
# to serve our HTML/WASM/ASM/JS files
COPY /public /usr/src/app/sserver/public

# Expose the ports we will be using
EXPOSE {EXPOSED_PORT}/tcp
EXPOSE {EXPOSED_PORT}/udp