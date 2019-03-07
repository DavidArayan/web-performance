#define TOTALTIME

#ifdef __EMSCRIPTEN__
	#define TIME_PRECISION 1000.0
#else
	#define TIME_PRECISION 1000.0
#endif

#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include "rand.h"

#if defined(TOTALTIME)
	#include <time.h>
#endif

#ifdef __EMSCRIPTEN__
	#include <emscripten.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __EMSCRIPTEN__
EMSCRIPTEN_KEEPALIVE
#endif
void linear_memaccess(int rand_num) {
	// our randomness source, initialised with seed of 42
	struct random *rand = fmath_random_make(42);

	int* source_access = (int*) malloc((rand_num * 2) * sizeof(int));
	int* destination = (int*) malloc(rand_num * sizeof(int));

	#ifdef TOTALTIME
		clock_t begin_t = clock();
		clock_t end_t = clock();
		double total_time = 0.0;
	#endif

	#ifdef TOTALTIME
		begin_t = clock();
	#endif

	for (int i = 0; i < (rand_num * 2); i++) {
		source_access[i] = (int)fmath_random_nexti(rand, 0, 200000);
	}

	#ifdef TOTALTIME
		end_t = clock();
		total_time = ((double)(end_t - begin_t) * TIME_PRECISION / (double)CLOCKS_PER_SEC);
		printf("assign random values time %f \n", total_time);
	#endif

	#ifdef TOTALTIME
		begin_t = clock();
	#endif

	int j = 0;

	for (int i = 0; i < (rand_num * 2); i+=2) {
		int dst_1 = source_access[i];
		int dst_2 = source_access[i + 1];

		destination[j] = dst_1 + dst_2;

		j++;
	}

	#ifdef TOTALTIME
		end_t = clock();
		total_time = ((double)(end_t - begin_t) * TIME_PRECISION / (double)CLOCKS_PER_SEC);
		printf("linear memory access time %f \n", total_time);
		printf("access first = %i last = %i \n", source_access[0], source_access[(rand_num * 2) - 1]);
		printf("destination first = %i last = %i \n", destination[0], destination[rand_num - 1]);
	#endif

	free(source_access);
	free(destination);
	fmath_random_free(rand);
}

int main(int argc, char **argv) {
	printf("Running Program!\n");

	if (argc <= 1) {
		printf("Cannot Run. Supply some arguments!\n");

		return 0;
	}

	printf("Time measurement: %f\n", TIME_PRECISION);
	printf("Time units are 1000.0 = 1ms precision\n");

	int iterations = atoi(argv[1]);

	printf("Performing Iterations = %i \n", iterations);
	linear_memaccess(iterations);

	return 0;
}

#ifdef __cplusplus
}
#endif