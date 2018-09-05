#include <stdlib.h>

#ifdef __EMSCRIPTEN__
	#include <emscripten.h>
#endif

struct random {
    long seed;
};

#ifdef __cplusplus
	extern "C" {
#endif

#ifdef __EMSCRIPTEN__
struct random* EMSCRIPTEN_KEEPALIVE fmath_random_make(long seed);
void EMSCRIPTEN_KEEPALIVE fmath_random_free(struct random *rand);
long EMSCRIPTEN_KEEPALIVE fmath_random_next(struct random *rand);

float EMSCRIPTEN_KEEPALIVE fmath_random_nextf(
	struct random *rand,
	float min, 
	float max, 
	float dev);

long EMSCRIPTEN_KEEPALIVE fmath_random_nexti(
	struct random *rand,
	long min, 
	long max);
#else
struct random* fmath_random_make(long seed);
void fmath_random_free(struct random *rand);
long fmath_random_next(struct random *rand);

float fmath_random_nextf(
	struct random *rand,
	float min, 
	float max, 
	float dev);

long fmath_random_nexti(
	struct random *rand,
	long min, 
	long max);
#endif

#ifdef __cplusplus
	}
#endif