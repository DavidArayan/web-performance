### About

The following experiment uses an original [Delaunay Triangulator](https://en.wikipedia.org/wiki/Delaunay_triangulation) **C** code written in 1993 by [Geoff Leach](https://www.rmit.edu.au/contact/staff-contacts/academic-staff/l/leach-mr-geoff). Small modifications to the timer functions were required to be able to compile and run using **ASM.js** and **WebAssembly**. The large majority of the code remains unchainged from the original source.

The purpose of this experiment is to observe the computational and runtime performance between C, ASM.js and WebAssembly. For initial runtime observations, hardware requirements and software versions used visit the [Wiki](https://github.com/DavidArayan/Performance-Research/wiki).

### Instructions

The following instructions have been tested on **macOS High Sierra Version 10.13.6 (17G65)**. You may need to modify/rewrite the provided scripts for your specific platform.

You will need to have the following tools installed on your system.
- bash 4.4
- gcc toolchain
- [emscripten](https://github.com/DavidArayan/Performance-Research/tree/master/emscripten)
- python

### Compilation

For a fresh compile, run the command below. The **compile.sh** will copy the original source to the required destinations and perform a full compile for **C**, **ASM.js** and **WebAssembly** targets. See the individual **Makefile** for more info.

```bash
sudo bash compile.sh dct
```

The above command will generate **_build** folders for each of the targets.

#### Running ASM.js

For the ASM.js variant of the code, run the command below. The command will launch a simple local python server for the selected target and serve the content on **port 8000**.

```bash
sudo bash serve.sh delaunay_asm
```

Open either **Chrome**, **Safari** or **Firefox** and navigate to the following address.

```bash
# Note the ?a1000, that is the argument to the program. 
# Increase the number to increase the number of points to triangulate
http://localhost:8000/dct.html?a1000
```

#### Running WebAssembly

For the WebAssembly variant of the code, run the command below. The command will launch a simple local python server for the selected target and serve the content on **port 8000**.

```bash
sudo bash serve.sh delaunay_wasm
```

Open either **Chrome**, **Safari** or **Firefox** and navigate to the following address.

```bash
# Note the ?a1000, that is the argument to the program. 
# Increase the number to increase the number of points to triangulate
http://localhost:8000/dct.html?a1000
```

#### Running C

For the C variant of the code, navigate to the **delaunay_original_build** folder and run the command below.

```bash
# Note the ?a1000, that is the argument to the program. 
# Increase the number to increase the number of points to triangulate
./dct a1000
```

### Cleanup

To perform cleanup, run the command below. This will clean all build targets and temporary files which were created during the Compile stage.

```bash
sudo bash clean.sh
```
