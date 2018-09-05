#include "rand.h"

#ifdef __cplusplus
	extern "C" {
#endif

#ifdef __EMSCRIPTEN__
struct random* EMSCRIPTEN_KEEPALIVE fmath_random_make(long seed)
#else
struct random* fmath_random_make(long seed)
#endif
{
	struct random* rand = (struct random*)malloc(sizeof(struct random));

	rand->seed = seed;

	return rand;
}

#ifdef __EMSCRIPTEN__
void EMSCRIPTEN_KEEPALIVE fmath_random_free(struct random *rand)
#else
void fmath_random_free(struct random *rand)
#endif
{
	free(rand);

	rand = 0;
}

#ifdef __EMSCRIPTEN__
long EMSCRIPTEN_KEEPALIVE fmath_random_next(struct random *rand)
#else
long fmath_random_next(struct random *rand)
#endif
{
	return 0;
}

#ifdef __EMSCRIPTEN__
float EMSCRIPTEN_KEEPALIVE fmath_random_nextf(
	struct random *rand,
	float min, 
	float max, 
	float dev)
#else
float fmath_random_nextf(
	struct random *rand,
	float min, 
	float max, 
	float dev)
#endif
{
	return 0.0f;
}

#ifdef __cplusplus
	}
#endif