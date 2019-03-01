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
	printf("Running Program!\n");

	if (argc <= 1) {
		printf("Cannot Run. Supply some arguments!\n");

		return 0;
	}

	printf("Time measurement: %f\n", TIME_PRECISION);
	printf("Time units are 1000.0 = 1ms precision\n");

	const int iterations = atoi(argv[1]);

	printf("Performing Iterations = %i \n", iterations);

	// our randomness source, initialised with seed of 42
	struct random *rand = fmath_random_make(42);

	// primary matrices, initialized to the identity matrix
	float *m_model = fmath_matrix4f_make();
	float *m_camera = fmath_matrix4f_make();
	float *m_proj = fmath_matrix4f_make();

	// make our mock perspective matrix
	fmath_matrix4f_make_perspective(m_proj, 50.0f, 800.0f / 600.0f, 1.0f, 500000.0f);

	// our operation buffers, these are here so we don't re-allocate
	// all the time and just measure raw compute performance
	float *m_camera_inv = fmath_matrix4f_make();
	float *mv = fmath_matrix4f_make();
	float *mvp = fmath_matrix4f_make();

	// our position, quaternion, scale values which we will use to
	// compose our matrices
	float model_position[3];
	float model_quaternion[4];
	float model_scale[] = {100.0f, 100.0f, 100.0f};

	float camera_position[3];
	float camera_quaternion[4];
	float camera_scale[] = {1.0f, 1.0f, 1.0f};

	// initialise timers if required
	#ifdef EMTIME
		// initialize variables
		clock_t begin = clock();
		clock_t end = clock();
		double time_spent_randomness = 0.0;
		double time_spent_randomness_assignment = 0.0;
		double time_spent_matrixinverse = 0.0;
		double time_spent_matrixmul = 0.0;
		double time_spent_matrixcompose = 0.0;
	#endif

	#ifdef TOTALTIME
		clock_t begin_t = clock();
		clock_t end_t = clock();
		double total_time = 0.0;
	#endif

	#ifdef TOTALTIME
		begin_t = clock();
	#endif

	for (int i = 0; i < iterations; i++) {
		// generate new random values for our matrices to keep the variance
		// going. Since the seed is always the same, this should yield consistent
		// results across multiple runs
		#ifdef EMTIME
			begin = clock();
		#endif

		const float model_position_x = fmath_random_nextf(rand, -2000.0f, 2000.0f, 100000.0f);
		const float model_position_y = fmath_random_nextf(rand, -2000.0f, 2000.0f, 100000.0f);
		const float model_position_z = fmath_random_nextf(rand, -2000.0f, 2000.0f, 100000.0f);

		const float camera_position_x = fmath_random_nextf(rand, -2000.0f, 2000.0f, 100000.0f);
		const float camera_position_y = fmath_random_nextf(rand, -2000.0f, 2000.0f, 100000.0f);
		const float camera_position_z = fmath_random_nextf(rand, -2000.0f, 2000.0f, 100000.0f);

		const float model_rot_x = fmath_random_nextf(rand, 0.0f, 1.0f, 100000.0f);
		const float model_rot_y = fmath_random_nextf(rand, 0.0f, 1.0f, 100000.0f);
		const float model_rot_z = fmath_random_nextf(rand, 0.0f, 1.0f, 100000.0f);
		const float model_rot_w = fmath_random_nextf(rand, 0.0f, 1.0f, 100000.0f);

		const float camera_rot_x = fmath_random_nextf(rand, 0.0f, 1.0f, 100000.0f);
		const float camera_rot_y = fmath_random_nextf(rand, 0.0f, 1.0f, 100000.0f);
		const float camera_rot_z = fmath_random_nextf(rand, 0.0f, 1.0f, 100000.0f);
		const float camera_rot_w = fmath_random_nextf(rand, 0.0f, 1.0f, 100000.0f);

		#ifdef EMTIME
			end = clock();
			time_spent_randomness += ((double)(end - begin) * TIME_PRECISION / (double)CLOCKS_PER_SEC);
		#endif

		// compute all our random positions, rotations for further operations
		#ifdef EMTIME
			begin = clock();
		#endif

		model_position[0] = model_position_x;
		model_position[1] = model_position_y;
		model_position[2] = model_position_z;

		camera_position[0] = camera_position_x;
		camera_position[1] = camera_position_y;
		camera_position[2] = camera_position_z;

		// the rotations are computed in a specific way to ensure that the final quaternion
		// is actually a valid rotational value from a mathematical sense
		float sum = 0;
		model_quaternion[3] = model_rot_w * 2.0f - 1.0f;
		sum += model_quaternion[3] * model_quaternion[3];

		model_quaternion[0] = sqrt(1.0f - sum) * (model_rot_x * 2.0f - 1.0f);
		sum += model_quaternion[0] * model_quaternion[0];

		model_quaternion[1] = sqrt(1.0f - sum) * (model_rot_y * 2.0f - 1.0f);
		sum += model_quaternion[1] * model_quaternion[1];

		model_quaternion[2] = sqrt(1.0f - sum) * (model_rot_z < 0.5f ? -1.0f : 1.0f);

		sum = 0;
		camera_quaternion[3] = camera_rot_w * 2.0f - 1.0f;
		sum += camera_quaternion[3] * camera_quaternion[3];

		camera_quaternion[0] = sqrt(1.0f - sum) * (camera_rot_x * 2.0f - 1.0f);
		sum += camera_quaternion[0] * camera_quaternion[0];

		camera_quaternion[1] = sqrt(1.0f - sum) * (camera_rot_y * 2.0f - 1.0f);
		sum += camera_quaternion[1] * camera_quaternion[1];

		camera_quaternion[2] = sqrt(1.0f - sum) * (camera_rot_z < 0.5f ? -1.0f : 1.0f);

		#ifdef EMTIME
			end = clock();
			time_spent_randomness_assignment += ((double)(end - begin) * TIME_PRECISION / (double)CLOCKS_PER_SEC);
		#endif

		// use this to re-compose all our matrices from our randomly generated data
		#ifdef EMTIME
			begin = clock();
		#endif

		fmath_matrix4f_compose(model_position, model_quaternion, model_scale, m_model);
		fmath_matrix4f_compose(camera_position, camera_quaternion, camera_scale, m_camera);

		#ifdef EMTIME
			end = clock();
			time_spent_matrixcompose += ((double)(end - begin) * TIME_PRECISION / (double)CLOCKS_PER_SEC);
		#endif

		// use this to invert our camera matrix (from world space to screen-space)
		#ifdef EMTIME
			begin = clock();
		#endif

		fmath_matrix4f_invert(m_camera, m_camera_inv);

		#ifdef EMTIME
			end = clock();
			time_spent_matrixinverse += ((double)(end - begin) * TIME_PRECISION / (double)CLOCKS_PER_SEC);
		#endif

		// perform our multiplication of the matrices
		#ifdef EMTIME
			begin = clock();
		#endif

		fmath_matrix4f_mul(m_camera_inv, m_model, mv);
		fmath_matrix4f_mul(m_proj, mv, mvp);

		#ifdef EMTIME
			end = clock();
			time_spent_matrixmul += ((double)(end - begin) * TIME_PRECISION / (double)CLOCKS_PER_SEC);
		#endif
	}

	#ifdef TOTALTIME
		end_t = clock();
		total_time = ((double)(end_t - begin_t) * TIME_PRECISION / (double)CLOCKS_PER_SEC);
	#endif

	#ifdef EMTIME
		printf("randomness (total time) %f \n", time_spent_randomness);
		printf("randomness assignment (total time) %f \n", time_spent_randomness_assignment);
		printf("matrix compose (total time) %f \n", time_spent_matrixcompose);
		printf("matrix invert (total time) %f \n", time_spent_matrixinverse);
		printf("matrix multiply (total time) %f \n", time_spent_matrixmul);
	#endif

	#ifdef TOTALTIME
		printf("total time %f \n", total_time);
	#endif

	fmath_matrix4f_free(m_model);
	fmath_matrix4f_free(m_camera);
	fmath_matrix4f_free(m_proj);

	fmath_matrix4f_free(m_camera_inv);
	fmath_matrix4f_free(mv);
	fmath_matrix4f_free(mvp);

	fmath_random_free(rand);

	printf("Finishing Program!\n");

	return 0;
}

#ifdef __cplusplus
	}
#endif