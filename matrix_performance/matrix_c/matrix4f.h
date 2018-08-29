#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __EMSCRIPTEN__
void EMSCRIPTEN_KEEPALIVE fmath_matrix4f_mul(float *lhs, float *rhs, float *result);
void EMSCRIPTEN_KEEPALIVE fmath_matrix4f_invert(float *matrix, float *result);
void EMSCRIPTEN_KEEPALIVE fmath_matrix4f_compose(float *position, float *orientation, float *scale, float *result);
void EMSCRIPTEN_KEEPALIVE fmath_matrix4f_identity(float *result);
void EMSCRIPTEN_KEEPALIVE fmath_matrix4f_free(float *matrix);

float* EMSCRIPTEN_KEEPALIVE fmath_matrix4f_make();
float EMSCRIPTEN_KEEPALIVE fmath_matrix4f_det(float *matrix);
#else
void fmath_matrix4f_mul(float *lhs, float *rhs, float *result);
void fmath_matrix4f_invert(float *matrix, float *result);
void fmath_matrix4f_compose(float *position, float *orientation, float *scale, float *result);
void fmath_matrix4f_identity(float *result);
void fmath_matrix4f_free(float *matrix);

float* fmath_matrix4f_make();
float fmath_matrix4f_det(float *matrix);
#endif

#ifdef __cplusplus
}
#endif