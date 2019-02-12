#ifdef __EMSCRIPTEN__
	#include <emscripten.h>
#endif

#ifdef __cplusplus
	extern "C" {
#endif

#ifdef __EMSCRIPTEN__
EMSCRIPTEN_KEEPALIVE
#endif
void say_hello();

#ifdef __cplusplus
	}
#endif