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

// our global variables
struct random *global_rand = NULL;
float *m_model = NULL;

#ifdef __EMSCRIPTEN__
EMSCRIPTEN_KEEPALIVE
#endif
float calculate_det() {
	float model_position[3];
	float model_quaternion[4];
	float model_scale[] = {1.0f, 1.0f, 1.0f};

	const float model_position_x = fmath_random_nextf(global_rand, -200.0f, 200.0f, 100000.0f);
	const float model_position_y = fmath_random_nextf(global_rand, -200.0f, 200.0f, 100000.0f);
	const float model_position_z = fmath_random_nextf(global_rand, -200.0f, 200.0f, 100000.0f);

	const float model_rot_x = fmath_random_nextf(global_rand, 0.0f, 1.0f, 100000.0f);
	const float model_rot_y = fmath_random_nextf(global_rand, 0.0f, 1.0f, 100000.0f);
	const float model_rot_z = fmath_random_nextf(global_rand, 0.0f, 1.0f, 100000.0f);
	const float model_rot_w = fmath_random_nextf(global_rand, 0.0f, 1.0f, 100000.0f);

	//printf("%f %f %f\n", model_position_x, model_position_y, model_position_z);
	//printf("%f %f %f %f\n", model_rot_x, model_rot_y, model_rot_z, model_rot_w);

	model_position[0] = model_position_x;
	model_position[1] = model_position_y;
	model_position[2] = model_position_z;

	float sum = 0;
	model_quaternion[3] = model_rot_w * 2.0f - 1.0f;
	sum += model_quaternion[3] * model_quaternion[3];

	model_quaternion[0] = sqrt(1.0f - sum) * (model_rot_x * 2.0f - 1.0f);
	sum += model_quaternion[0] * model_quaternion[0];

	model_quaternion[1] = sqrt(1.0f - sum) * (model_rot_y * 2.0f - 1.0f);
	sum += model_quaternion[1] * model_quaternion[1];

	model_quaternion[2] = sqrt(1.0f - sum) * (model_rot_z < 0.5f ? -1.0f : 1.0f);

	fmath_matrix4f_compose(model_position, model_quaternion, model_scale, m_model);

	// calculate and return the matrix determinant
	return fmath_matrix4f_det(m_model);
}

#ifdef __EMSCRIPTEN__
EMSCRIPTEN_KEEPALIVE
#endif
void free_buffers() {
	printf("fncall - free buffers.\n");
	fmath_matrix4f_free(m_model);
	fmath_random_free(global_rand);
}

#ifdef __EMSCRIPTEN__
EMSCRIPTEN_KEEPALIVE
#endif
void alloc_buffers() {
	printf("fncall - allocated buffers.\n");
	global_rand = fmath_random_make(4873);
	m_model = fmath_matrix4f_make();
}

int main(int argc, char *argv[]) {
	#ifdef __EMSCRIPTEN__
		// WASM/ASM.js outputs are controlled via JavaScript
		alloc_buffers();
	#else
		printf("fncall experiment is designed to run only on WASM/ASM.js\n");
		printf("below is a sample output to test functionality\n");

		alloc_buffers();

		printf("output = %f\n", calculate_det());

		free_buffers();
	#endif
	return 0;
}

#ifdef __cplusplus
	}
#endif