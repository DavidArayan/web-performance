#include "matrix4f.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __EMSCRIPTEN__
void EMSCRIPTEN_KEEPALIVE fmath_matrix4f_mul(
	float *lhs, 
	float *rhs, 
	float *result)
#else
void fmath_matrix4f_mul(
	float *lhs, 
	float *rhs, 
	float *result)
#endif
{
#ifdef SIMD_MATH_ENABLED
	__m128 row1 = _mm_load_ps(&rhs[0]);
	__m128 row2 = _mm_load_ps(&rhs[4]);
	__m128 row3 = _mm_load_ps(&rhs[8]);
	__m128 row4 = _mm_load_ps(&rhs[12]);

	for (int i=0; i<4; i++) {
		__m128 brod1 = _mm_set1_ps(lhs[4 * i + 0]);
		__m128 brod2 = _mm_set1_ps(lhs[4 * i + 1]);
		__m128 brod3 = _mm_set1_ps(lhs[4 * i + 2]);
		__m128 brod4 = _mm_set1_ps(lhs[4 * i + 3]);

		__m128 row = _mm_add_ps(
			_mm_add_ps(
				_mm_mul_ps(brod1, row1),
				_mm_mul_ps(brod2, row2)),
			_mm_add_ps(
				_mm_mul_ps(brod3, row3),
				_mm_mul_ps(brod4, row4)));

		_mm_store_ps(&result[4 * i], row);
	}
#else
	const float a44 = lhs[15];
	const float a11 = lhs[0];
	const float a21 = lhs[1];
	const float a31 = lhs[2];
	const float a41 = lhs[3];

	const float a12 = lhs[4];
	const float a22 = lhs[5];
	const float a32 = lhs[6];
	const float a42 = lhs[7];

	const float a13 = lhs[8];
	const float a23 = lhs[9];
	const float a33 = lhs[10];
	const float a43 = lhs[11];

	const float a14 = lhs[12];
	const float a24 = lhs[13];
	const float a34 = lhs[14];

	const float b44 = rhs[15];
	const float b11 = rhs[0];
	const float b21 = rhs[1];
	const float b31 = rhs[2];
	const float b41 = rhs[3];

	const float b12 = rhs[4];
	const float b22 = rhs[5];
	const float b32 = rhs[6];
	const float b42 = rhs[7];

	const float b13 = rhs[8];
	const float b23 = rhs[9];
	const float b33 = rhs[10];
	const float b43 = rhs[11];

	const float b14 = rhs[12];
	const float b24 = rhs[13];
	const float b34 = rhs[14];

	const float te0 = a11 * b11 + a12 * b21 + a13 * b31 + a14 * b41;
	const float te4 = a11 * b12 + a12 * b22 + a13 * b32 + a14 * b42;
	const float te8 = a11 * b13 + a12 * b23 + a13 * b33 + a14 * b43;
	const float te12 = a11 * b14 + a12 * b24 + a13 * b34 + a14 * b44;

	const float te1 = a21 * b11 + a22 * b21 + a23 * b31 + a24 * b41;
	const float te5 = a21 * b12 + a22 * b22 + a23 * b32 + a24 * b42;
	const float te9 = a21 * b13 + a22 * b23 + a23 * b33 + a24 * b43;
	const float te13 = a21 * b14 + a22 * b24 + a23 * b34 + a24 * b44;

	const float te2 = a31 * b11 + a32 * b21 + a33 * b31 + a34 * b41;
	const float te6 = a31 * b12 + a32 * b22 + a33 * b32 + a34 * b42;
	const float te10 = a31 * b13 + a32 * b23 + a33 * b33 + a34 * b43;
	const float te14 = a31 * b14 + a32 * b24 + a33 * b34 + a34 * b44;

	const float te3 = a41 * b11 + a42 * b21 + a43 * b31 + a44 * b41;
	const float te7 = a41 * b12 + a42 * b22 + a43 * b32 + a44 * b42;
	const float te11 = a41 * b13 + a42 * b23 + a43 * b33 + a44 * b43;
	const float te15 = a41 * b14 + a42 * b24 + a43 * b34 + a44 * b44;

	result[15] = te15;
	result[0] = te0;
	result[1] = te1;
	result[2] = te2;
	result[3] = te3;

	result[4] = te4;
	result[5] = te5;
	result[6] = te6;
	result[7] = te7;

	result[8] = te8;
	result[9] = te9;
	result[10] = te10;
	result[11] = te11;

	result[12] = te12;
	result[13] = te13;
	result[14] = te14;
#endif
}

#ifdef __EMSCRIPTEN__
void EMSCRIPTEN_KEEPALIVE fmath_matrix4f_invert(
	float *matrix, 
	float *result)
#else
void fmath_matrix4f_invert(
	float *matrix, 
	float *result)
#endif
{
	const float n44 = matrix[15];
	const float n11 = matrix[0];
	const float n21 = matrix[1];
	const float n31 = matrix[2];
	const float n41 = matrix[3];

	const float n12 = matrix[4];
	const float n22 = matrix[5];
	const float n32 = matrix[6];
	const float n42 = matrix[7];

	const float n13 = matrix[8];
	const float n23 = matrix[9];
	const float n33 = matrix[10];
	const float n43 = matrix[11];

	const float n14 = matrix[12];
	const float n24 = matrix[13];
	const float n34 = matrix[14];

	const float t11 = n23 * n34 * n42 - n24 * n33 * n42 + n24 * n32 * n43 - n22 * n34 * n43 - n23 * n32 * n44 + n22 * n33 * n44;
	const float t12 = n14 * n33 * n42 - n13 * n34 * n42 - n14 * n32 * n43 + n12 * n34 * n43 + n13 * n32 * n44 - n12 * n33 * n44;
	const float t13 = n13 * n24 * n42 - n14 * n23 * n42 + n14 * n22 * n43 - n12 * n24 * n43 - n13 * n22 * n44 + n12 * n23 * n44;
	const float t14 = n14 * n23 * n32 - n13 * n24 * n32 - n14 * n22 * n33 + n12 * n24 * n33 + n13 * n22 * n34 - n12 * n23 * n34;

	const float det = n11 * t11 + n21 * t12 + n31 * t13 + n41 * t14;
	const float inv_det = 1.0f / det;

	const float te0 = t11 * inv_det;
	const float te1 = (n24 * n33 * n41 - n23 * n34 * n41 - n24 * n31 * n43 + n21 * n34 * n43 + n23 * n31 * n44 - n21 * n33 * n44) * inv_det;
	const float te2 = (n22 * n34 * n41 - n24 * n32 * n41 + n24 * n31 * n42 - n21 * n34 * n42 - n22 * n31 * n44 + n21 * n32 * n44) * inv_det;
	const float te3 = (n23 * n32 * n41 - n22 * n33 * n41 - n23 * n31 * n42 + n21 * n33 * n42 + n22 * n31 * n43 - n21 * n32 * n43) * inv_det;

	const float te4 = t12 * inv_det;
	const float te5 = (n13 * n34 * n41 - n14 * n33 * n41 + n14 * n31 * n43 - n11 * n34 * n43 - n13 * n31 * n44 + n11 * n33 * n44) * inv_det;
	const float te6 = (n14 * n32 * n41 - n12 * n34 * n41 - n14 * n31 * n42 + n11 * n34 * n42 + n12 * n31 * n44 - n11 * n32 * n44) * inv_det;
	const float te7 = (n12 * n33 * n41 - n13 * n32 * n41 + n13 * n31 * n42 - n11 * n33 * n42 - n12 * n31 * n43 + n11 * n32 * n43) * inv_det;

	const float te8 = t13 * inv_det;
	const float te9 = (n14 * n23 * n41 - n13 * n24 * n41 - n14 * n21 * n43 + n11 * n24 * n43 + n13 * n21 * n44 - n11 * n23 * n44) * inv_det;
	const float te10 = (n12 * n24 * n41 - n14 * n22 * n41 + n14 * n21 * n42 - n11 * n24 * n42 - n12 * n21 * n44 + n11 * n22 * n44) * inv_det;
	const float te11 = (n13 * n22 * n41 - n12 * n23 * n41 - n13 * n21 * n42 + n11 * n23 * n42 + n12 * n21 * n43 - n11 * n22 * n43) * inv_det;

	const float te12 = t14 * inv_det;
	const float te13 = (n13 * n24 * n31 - n14 * n23 * n31 + n14 * n21 * n33 - n11 * n24 * n33 - n13 * n21 * n34 + n11 * n23 * n34) * inv_det;
	const float te14 = (n14 * n22 * n31 - n12 * n24 * n31 - n14 * n21 * n32 + n11 * n24 * n32 + n12 * n21 * n34 - n11 * n22 * n34) * inv_det;
	const float te15 = (n12 * n23 * n31 - n13 * n22 * n31 + n13 * n21 * n32 - n11 * n23 * n32 - n12 * n21 * n33 + n11 * n22 * n33) * inv_det;

	result[15] = te15;
	result[0] = te0;
	result[1] = te1;
	result[2] = te2;
	result[3] = te3;

	result[4] = te4;
	result[5] = te5;
	result[6] = te6;
	result[7] = te7;

	result[8] = te8;
	result[9] = te9;
	result[10] = te10;
	result[11] = te11;

	result[12] = te12;
	result[13] = te13;
	result[14] = te14;
}

#ifdef __EMSCRIPTEN__
float EMSCRIPTEN_KEEPALIVE fmath_matrix4f_det(float *matrix)
#else
float fmath_matrix4f_det(float *matrix)
#endif
{
	const float n44 = matrix[15];
	const float n11 = matrix[0];
	const float n21 = matrix[1];
	const float n31 = matrix[2];
	const float n41 = matrix[3];

	const float n12 = matrix[4];
	const float n22 = matrix[5];
	const float n32 = matrix[6];
	const float n42 = matrix[7];

	const float n13 = matrix[8];
	const float n23 = matrix[9];
	const float n33 = matrix[10];
	const float n43 = matrix[11];

	const float n14 = matrix[12];
	const float n24 = matrix[13];
	const float n34 = matrix[14];

	const float t11 = n23 * n34 * n42 - n24 * n33 * n42 + n24 * n32 * n43 - n22 * n34 * n43 - n23 * n32 * n44 + n22 * n33 * n44;
	const float t12 = n14 * n33 * n42 - n13 * n34 * n42 - n14 * n32 * n43 + n12 * n34 * n43 + n13 * n32 * n44 - n12 * n33 * n44;
	const float t13 = n13 * n24 * n42 - n14 * n23 * n42 + n14 * n22 * n43 - n12 * n24 * n43 - n13 * n22 * n44 + n12 * n23 * n44;
	const float t14 = n14 * n23 * n32 - n13 * n24 * n32 - n14 * n22 * n33 + n12 * n24 * n33 + n13 * n22 * n34 - n12 * n23 * n34;

	const float det = n11 * t11 + n21 * t12 + n31 * t13 + n41 * t14;

	return det;
}

#ifdef __EMSCRIPTEN__
void EMSCRIPTEN_KEEPALIVE fmath_matrix4f_compose(
	float *position, 
	float *orientation, 
	float *scale, 
	float *result)
#else
void fmath_matrix4f_compose(
	float *position, 
	float *orientation, 
	float *scale, 
	float *result)
#endif
{
	const float qw = orientation[3];
	const float qx = orientation[0];
	const float qy = orientation[1];
	const float qz = orientation[2];

	const float pz = position[2];
	const float px = position[0];
	const float py = position[1];

	const float sz = scale[2];
	const float sx = scale[0];
	const float sy = scale[1];

	const float qx2 = qx + qx;
	const float qy2 = qy + qy;
	const float qz2 = qz + qz;

	const float qxx = qx * qx2;
	const float qxy = qx * qy2;
	const float qxz = qx * qz2;

	const float qyy = qy * qy2;
	const float qyz = qy * qz2;
	const float qzz = qz * qz2;

	const float qwx = qw * qx2;
	const float qwy = qw * qy2;
	const float qwz = qw * qz2;

	const float te0 = (1.0f - (qyy + qzz)) * sx;
	const float te1 = (qxy + qwz) * sx;
	const float te2 = (qxz - qwy) * sx;
	const float te3 = 0.0f;

	const float te4 = (qxy - qwz) * sy;
	const float te5 = (1.0f - (qxx + qzz)) * sy;
	const float te6 = (qyz + qwx) * sy;
	const float te7 = 0.0f;

	const float te8 = (qxz + qwy) * sz;
	const float te9 = (qyz - qwx) * sz;
	const float te10 = (1.0f - (qxx + qyy)) * sz;
	const float te11 = 0.0f;

	const float te12 = px;
	const float te13 = py;
	const float te14 = pz;
	const float te15 = 1.0f;

	result[15] = te15;
	result[0] = te0;
	result[1] = te1;
	result[2] = te2;
	result[3] = te3;

	result[4] = te4;
	result[5] = te5;
	result[6] = te6;
	result[7] = te7;

	result[8] = te8;
	result[9] = te9;
	result[10] = te10;
	result[11] = te11;

	result[12] = te12;
	result[13] = te13;
	result[14] = te14;
}

#ifdef __EMSCRIPTEN__
void EMSCRIPTEN_KEEPALIVE fmath_matrix4f_identity(float *result)
#else
void fmath_matrix4f_identity(float *result)
#endif
{
	result[15] = 1.0f;
	result[0] = 1.0f;
	result[1] = 0.0f;
	result[2] = 0.0f;
	result[3] = 0.0f;

	result[4] = 0.0f;
	result[5] = 1.0f;
	result[6] = 0.0f;
	result[7] = 0.0f;

	result[8] = 0.0f;
	result[9] = 0.0f;
	result[10] = 1.0f;
	result[11] = 0.0f;

	result[12] = 0.0f;
	result[13] = 0.0f;
	result[14] = 0.0f;
}

#ifdef __EMSCRIPTEN__
void EMSCRIPTEN_KEEPALIVE fmath_matrix4f_perspective(
	float *matrix, 
	float left, 
	float right, 
	float top, 
	float bottom, 
	float near, 
	float far)
#else
void fmath_matrix4f_perspective(
	float *matrix, 
	float left, 
	float right, 
	float top, 
	float bottom, 
	float near, 
	float far)
#endif
{
	const float x = 2.0f * near / (right - left);
	const float y = 2.0f * near / (top - bottom);

	const float a = (right + left) / (right - left);
	const float b = (top + bottom) / (top - bottom);
	const float c = -(far + near) / (far - near);
	const float d = -2.0f * far * near / (far - near);

	matrix[15] = 0.0f;
	matrix[0] = x;
	matrix[1] = 0.0f;
	matrix[2] = 0.0f;
	matrix[3] = 0.0f;

	matrix[4] = 0.0f;
	matrix[5] = y;
	matrix[6] = 0.0f;
	matrix[7] = 0.0f;

	matrix[8] = a;
	matrix[9] = b;
	matrix[10] = c;
	matrix[11] = -1.0f;

	matrix[12] = 0.0f;
	matrix[13] = 0.0f;
	matrix[14] = d;
}

#ifdef __EMSCRIPTEN__
void EMSCRIPTEN_KEEPALIVE fmath_matrix4f_make_perspective(
	float *matrix, 
	float fov, 
	float aspect, 
	float near, 
	float far)
#else
void fmath_matrix4f_make_perspective(
	float *matrix, 
	float fov, 
	float aspect, 
	float near, 
	float far)
#endif
{
	const float m_top = near * (float)(tan((3.14159265358979323846 / 180.0) * 0.5 * fov));
	const float m_height = 2.0f * m_top;
	const float m_width = aspect * m_height;
	const float m_left = -0.5f * m_width;

	fmath_matrix4f_perspective(
		matrix, 
		m_left, 
		m_left + m_width, 
		m_top, 
		m_top - m_height, 
		near, 
		far);
}

#ifdef __EMSCRIPTEN__
void EMSCRIPTEN_KEEPALIVE fmath_matrix4f_free(float *matrix)
#else
void fmath_matrix4f_free(float *matrix)
#endif
{
	free(matrix);

	// reset the pointer
	matrix = 0;
}

#ifdef __EMSCRIPTEN__
float* EMSCRIPTEN_KEEPALIVE fmath_matrix4f_make()
#else
float* fmath_matrix4f_make()
#endif
{
	// allocate our memory pool to hold a 4x4 matrix
	float *matrix = (float*)malloc(16 * sizeof(float));
	// set the matrix into the identity
	fmath_matrix4f_identity(matrix);

	return matrix;
}

#ifdef __cplusplus
}
#endif