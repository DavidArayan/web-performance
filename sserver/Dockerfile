FROM node:11.9.0-alpine

WORKDIR /usr/src/app

# Grab http-server to serve our simple HTML files
RUN npm install http-server -g && \
	mkdir -p /usr/src/app/sserver/public

# Copy all our files into the public directory which will be used
# to serve our HTML/WASM/ASM/JS files
COPY /public /usr/src/app/sserver/public

# Expose the ports we will be using
EXPOSE 8080/tcp
EXPOSE 8080/udp