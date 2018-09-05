#define EMTIME

#ifdef __EMSCRIPTEN__
	#include <emscripten.h>
#endif

#ifdef EMTIME
	#include <time.h>
#endif

#include "matrix4f.h"

#ifdef __cplusplus
	extern "C" {
#endif

int main(int argc, char** argv) {
	return 0;
}

#ifdef __cplusplus
	}
#endif