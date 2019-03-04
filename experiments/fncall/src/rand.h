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
EMSCRIPTEN_KEEPALIVE
#endif
struct random* fmath_random_make(long seed);

#ifdef __EMSCRIPTEN__
EMSCRIPTEN_KEEPALIVE
#endif
void fmath_random_free(struct random *rand);

#ifdef __EMSCRIPTEN__
EMSCRIPTEN_KEEPALIVE
#endif
long fmath_random_next(struct random *rand);

#ifdef __EMSCRIPTEN__
EMSCRIPTEN_KEEPALIVE
#endif
float fmath_random_nextf(
	struct random *rand,
	float min, 
	float max, 
	float dev);

#ifdef __EMSCRIPTEN__
EMSCRIPTEN_KEEPALIVE
#endif
long fmath_random_nexti(
	struct random *rand,
	long min, 
	long max);

#ifdef __cplusplus
	}
#endif