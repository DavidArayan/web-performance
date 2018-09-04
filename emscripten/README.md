#### About

All **ASM.js** and **WebAssembly** targets refer to this folder for the [Emscripten SDK](https://github.com/kripken/emscripten). Please visit the [Emscripten Getting Started](https://kripken.github.io/emscripten-site/docs/getting_started/downloads.html) For detailed instructions on how to pull, compile and setup Emscripten for your specific platform.

#### Instructions

The following instructions have been tested on **macOS High Sierra Version 10.13.6 (17G65)**. You may need to modify/rewrite the provided scripts for your specific platform.

You will need to have the following tools installed on your system.
- git
- bash 4.4

###### Installation

for a fresh install, run the command below. The **install.sh** will pull, compile, install and activate the Emscripten SDK.

```bash
sudo bash install.sh
```

###### Activation

If you have a previous installation of Emscripten SDK, you can copy the **emsdk** folder into the current folder and run the command below.

```bash
sudo bash activate.sh
```
