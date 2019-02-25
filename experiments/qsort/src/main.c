#define TOTALTIME
#define TIME_PRECISION 100.0

#include <iostream>
#include <cstdlib>
#include <climits>
#include <stdio.h>
#include "main.h"
#include "rand.h"

#ifdef __EMSCRIPTEN__
	#include <emscripten.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __EMSCRIPTEN__
EMSCRIPTEN_KEEPALIVE
#endif
void qsort_rand(int rand_num) {
	// our randomness source, initialised with seed of 42
	struct random *rand = fmath_random_make(42);

	int a[rand_num] = {};

	#ifdef TOTALTIME
		clock_t begin_t = clock();
		clock_t end_t = clock();
		double total_time = 0.0;
	#endif

	#ifdef TOTALTIME
		begin_t = clock();
	#endif

	for (int i = 0; i < rand_num; i++) {
		a[i] = (int)fmath_random_nexti(rand, -200000, 200000);
	}

	#ifdef TOTALTIME
		end_t = clock();
		total_time = ((double)(end_t - begin_t) * TIME_PRECISION / (double)CLOCKS_PER_SEC);
		printf("assign random values time %f \n", total_time);
	#endif

    constexpr std::size_t size = sizeof a / sizeof *a;

    #ifdef TOTALTIME
		begin_t = clock();
	#endif
 
    std::qsort(a, size, sizeof *a, [] (const void* a, const void* b) {
        int arg1 = *static_cast<const int*>(a);
        int arg2 = *static_cast<const int*>(b);
 
        if (arg1 < arg2) {
        	return -1;
        }

        if (arg1 > arg2) {
        	return 1;
        }

        return 0;
    });

    #ifdef TOTALTIME
		end_t = clock();
		total_time = ((double)(end_t - begin_t) * TIME_PRECISION / (double)CLOCKS_PER_SEC);
		printf("qsort time %f \n", total_time);
	#endif
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
	qsort_rand(iterations);

	return 0;
}

#ifdef __cplusplus
}
#endif