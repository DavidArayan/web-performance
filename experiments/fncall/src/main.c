#define EMTIME
#define TOTALTIME

#ifdef __EMSCRIPTEN__
	#define TIME_PRECISION 1000.0
#else
	#define TIME_PRECISION 1000.0
#endif

#ifdef __EMSCRIPTEN__
	#include <emscripten.h>
#endif

#if defined(EMTIME) || defined(TOTALTIME)
	#include <time.h>
#endif

#include <stdio.h>
#include "matrix4f.h"
#include "rand.h"

#ifdef __cplusplus
	extern "C" {
#endif

int main(int argc, char *argv[]) {
	return 0;
}

#ifdef __cplusplus
	}
#endif