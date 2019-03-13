[![Twitter: @DavidArayan](https://img.shields.io/badge/contact-DavidArayan-blue.svg?style=flat)](https://twitter.com/DavidArayan)
[![License](https://img.shields.io/badge/license-MIT-orange.svg?style=flat)](LICENSE)

### About
This repository contains code and samples that are used to conduct performance research experiments in C/C++, WebAssembly, ASM.js and JavaScript. The purpose of these experiments is to observe the execution speed between native C/C++ programs against WebAssembly, ASM.js and JavaScript.

### Tool Requirements
These tools are used to compile the code samples for the various platforms.

- [Docker](https://www.docker.com/) is used to remove the platform dependency issue when installing/configuring emscripten. Docker is free to install and run. This repository uses docker to compile ASM/WASM and Javascript experiments. Docker is available for Window, Mac and Linux.
- [Ruby](https://www.ruby-lang.org/en/) is used to automate compilation tasks.

### Building and Running ASM.js, WASM and JavaScript experiments
Build the Emscripten and Simple Server containers.

```shell
# Build both the Emscripten and Simple Server Containers
sh build.sh

# OR build them individually as shown below

# build Emscripten
sh emscripten_build.sh

# Build Simple Server
sh sserver_build.sh
```

Compile ASM.js, WASM and JavaScript experiments. This command will automatically compile all experiments and setup to run them on a local server.

```shell
sh emscripten_up.sh
```

Running the ASM.js, WASM and JavaScript experiments. This command will host a simple server on a local machine which will allow interacting with the experiments.

```shell
# This will bring up Simple Server container and host the experiments
# Internally this uses NodeJS and hosts the files on port 8080
# Existing the container using Ctrl-C
sh sserver_up.sh

# Once finished, bring the server down using this command
sh sserver_down.sh
```

Cleanup all containers. This command will cleanup all built containers from the system

```shell
# this will cleanup both Emscripten and Simple Server containers.
# NOTE: to run them again, you will need to rebuild
sh nuke.sh

# OR clean them individually

# Cleanup emscripten
sh emscripten_clean.sh

# Cleanup Simple Server
sh sserver_clean.sh
```

### Building and Running C/C++ experiments
C/C++ experiments need to compile and run on the target machine, as such we cannot use Docker for this.

1. Navigate to experiments folder
2. Run the compile.rb script as follows

```shell
# This will compile all experiments
ruby compile.rb
```

Once the script has completed, the compiled programs will be in a folder **compiled**.
