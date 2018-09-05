#define EMTIME

#ifdef __EMSCRIPTEN__
	#include <emscripten.h>
#endif

#ifdef EMTIME
	#include <time.h>
#endif

#include <stdio.h>
#include "matrix4f.h"
#include "rand.h"

#ifdef __cplusplus
	extern "C" {
#endif

int main(int argc, char** argv) {
	struct random *rand = fmath_random_make(42);

	for (int i = 0; i < 1000; i++) {
		float random_num = fmath_random_nextf(rand, -3.0f, 13.0f, 1000.0f);

		printf("number = %f \n", random_num);
	}

	return 0;
}

#ifdef __cplusplus
	}
#endif