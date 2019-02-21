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

int main(int argc, char **argv) {
	say_hello();
	return 0;
}

#ifdef __cplusplus
}
#endif