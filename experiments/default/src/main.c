#include <stdio.h>
#include "main.h"

#ifdef __EMSCRIPTEN__
	#include <emscripten.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __EMSCRIPTEN__
EMSCRIPTEN_KEEPALIVE
#endif
void say_hello() {
	printf("Hello World!\n");
}

#ifdef __EMSCRIPTEN__
EMSCRIPTEN_KEEPALIVE
#endif
int main_web(int argc, char **argv) {
	say_hello();

	return 0;
}

/**
 * Main is only compiled for non web targets
 */
#ifndef __EMSCRIPTEN__
int main(int argc, char **argv) {
	return main_web(argc, argv);
}
#endif

#ifdef __cplusplus
}
#endif