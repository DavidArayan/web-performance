#include "rand.h"

#ifdef __cplusplus
	extern "C" {
#endif

#ifdef __EMSCRIPTEN__
EMSCRIPTEN_KEEPALIVE
#endif
struct random* fmath_random_make(long seed)
{
	struct random* rand = (struct random*)malloc(sizeof(struct random));

	rand->seed = labs(seed);

	return rand;
}

#ifdef __EMSCRIPTEN__
EMSCRIPTEN_KEEPALIVE
#endif
void fmath_random_free(struct random *rand)
{
	free(rand);

	rand = 0;
}

#ifdef __EMSCRIPTEN__
EMSCRIPTEN_KEEPALIVE
#endif
long fmath_random_next(struct random *rand)
{
	long seed = rand->seed;

	seed ^= (seed << 13);
	seed ^= (seed >> 7);
	seed ^= (seed << 17);
	seed = labs(seed);

	rand->seed = seed;
	return seed;
}

#ifdef __EMSCRIPTEN__
EMSCRIPTEN_KEEPALIVE
#endif
float fmath_random_nextf(
	struct random *rand,
	float min, 
	float max, 
	float dev)
{
	const long lmin = (long)(min * dev);
	const long lmax = (long)(max * dev);
	const long rand_number = fmath_random_nexti(rand, lmin, lmax);
	const double rand_number_d = (double)(rand_number) / dev;

	return (float)rand_number_d;
}

#ifdef __EMSCRIPTEN__
EMSCRIPTEN_KEEPALIVE
#endif
long fmath_random_nexti(
	struct random *rand,
	long min, 
	long max)
{
	if (min > max) {
		return fmath_random_nexti(rand, max, min);
	}

	if (min == max) {
		return min;
	}

	const long rand_num = fmath_random_next(rand);

	return (rand_num % (max + 1 - min)) + min;
}

#ifdef __cplusplus
	}
#endif