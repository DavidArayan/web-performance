class Matrix4f {

	constructor(backing) {
		this.matrix = backing || new Float32Array(16);

		this.identity();
	}

	mul(rMatrix, res) {
		res = res || new Matrix4f();

		const lhs = this.matrix;
		const rhs = rMatrix.matrix;
		const result = res.matrix;

		const a11 = lhs[0];
		const a21 = lhs[1];
		const a31 = lhs[2];
		const a41 = lhs[3];

		const a12 = lhs[4];
		const a22 = lhs[5];
		const a32 = lhs[6];
		const a42 = lhs[7];

		const a13 = lhs[8];
		const a23 = lhs[9];
		const a33 = lhs[10];
		const a43 = lhs[11];

		const a14 = lhs[12];
		const a24 = lhs[13];
		const a34 = lhs[14];
		const a44 = lhs[15];

		const b11 = rhs[0];
		const b21 = rhs[1];
		const b31 = rhs[2];
		const b41 = rhs[3];

		const b12 = rhs[4];
		const b22 = rhs[5];
		const b32 = rhs[6];
		const b42 = rhs[7];

		const b13 = rhs[8];
		const b23 = rhs[9];
		const b33 = rhs[10];
		const b43 = rhs[11];

		const b14 = rhs[12];
		const b24 = rhs[13];
		const b34 = rhs[14];
		const b44 = rhs[15];

		const te0 = a11 * b11 + a12 * b21 + a13 * b31 + a14 * b41;
		const te4 = a11 * b12 + a12 * b22 + a13 * b32 + a14 * b42;
		const te8 = a11 * b13 + a12 * b23 + a13 * b33 + a14 * b43;
		const te12 = a11 * b14 + a12 * b24 + a13 * b34 + a14 * b44;

		const te1 = a21 * b11 + a22 * b21 + a23 * b31 + a24 * b41;
		const te5 = a21 * b12 + a22 * b22 + a23 * b32 + a24 * b42;
		const te9 = a21 * b13 + a22 * b23 + a23 * b33 + a24 * b43;
		const te13 = a21 * b14 + a22 * b24 + a23 * b34 + a24 * b44;

		const te2 = a31 * b11 + a32 * b21 + a33 * b31 + a34 * b41;
		const te6 = a31 * b12 + a32 * b22 + a33 * b32 + a34 * b42;
		const te10 = a31 * b13 + a32 * b23 + a33 * b33 + a34 * b43;
		const te14 = a31 * b14 + a32 * b24 + a33 * b34 + a34 * b44;

		const te3 = a41 * b11 + a42 * b21 + a43 * b31 + a44 * b41;
		const te7 = a41 * b12 + a42 * b22 + a43 * b32 + a44 * b42;
		const te11 = a41 * b13 + a42 * b23 + a43 * b33 + a44 * b43;
		const te15 = a41 * b14 + a42 * b24 + a43 * b34 + a44 * b44;

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
		result[15] = te15;

		return res;
	}

	invert(res) {
		res = res || new Matrix4f();

		const result = res.matrix;
		const matrix = this.matrix;

		const n11 = matrix[0];
		const n21 = matrix[1];
		const n31 = matrix[2];
		const n41 = matrix[3];

		const n12 = matrix[4];
		const n22 = matrix[5];
		const n32 = matrix[6];
		const n42 = matrix[7];

		const n13 = matrix[8];
		const n23 = matrix[9];
		const n33 = matrix[10];
		const n43 = matrix[11];

		const n14 = matrix[8];
		const n24 = matrix[9];
		const n34 = matrix[10];
		const n44 = matrix[11];

		const t11 = n23 * n34 * n42 - n24 * n33 * n42 + n24 * n32 * n43 - n22 * n34 * n43 - n23 * n32 * n44 + n22 * n33 * n44;
		const t12 = n14 * n33 * n42 - n13 * n34 * n42 - n14 * n32 * n43 + n12 * n34 * n43 + n13 * n32 * n44 - n12 * n33 * n44;
		const t13 = n13 * n24 * n42 - n14 * n23 * n42 + n14 * n22 * n43 - n12 * n24 * n43 - n13 * n22 * n44 + n12 * n23 * n44;
		const t14 = n14 * n23 * n32 - n13 * n24 * n32 - n14 * n22 * n33 + n12 * n24 * n33 + n13 * n22 * n34 - n12 * n23 * n34;

		const det = n11 * t11 + n21 * t12 + n31 * t13 + n41 * t14;
		const inv_det = 1.0 / det;

		const te0 = t11 * inv_det;
		const te1 = (n24 * n33 * n41 - n23 * n34 * n41 - n24 * n31 * n43 + n21 * n34 * n43 + n23 * n31 * n44 - n21 * n33 * n44) * inv_det;
		const te2 = (n22 * n34 * n41 - n24 * n32 * n41 + n24 * n31 * n42 - n21 * n34 * n42 - n22 * n31 * n44 + n21 * n32 * n44) * inv_det;
		const te3 = (n23 * n32 * n41 - n22 * n33 * n41 - n23 * n31 * n42 + n21 * n33 * n42 + n22 * n31 * n43 - n21 * n32 * n43) * inv_det;

		const te4 = t12 * inv_det;
		const te5 = (n13 * n34 * n41 - n14 * n33 * n41 + n14 * n31 * n43 - n11 * n34 * n43 - n13 * n31 * n44 + n11 * n33 * n44) * inv_det;
		const te6 = (n14 * n32 * n41 - n12 * n34 * n41 - n14 * n31 * n42 + n11 * n34 * n42 + n12 * n31 * n44 - n11 * n32 * n44) * inv_det;
		const te7 = (n12 * n33 * n41 - n13 * n32 * n41 + n13 * n31 * n42 - n11 * n33 * n42 - n12 * n31 * n43 + n11 * n32 * n43) * inv_det;

		const te8 = t13 * inv_det;
		const te9 = (n14 * n23 * n41 - n13 * n24 * n41 - n14 * n21 * n43 + n11 * n24 * n43 + n13 * n21 * n44 - n11 * n23 * n44) * inv_det;
		const te10 = (n12 * n24 * n41 - n14 * n22 * n41 + n14 * n21 * n42 - n11 * n24 * n42 - n12 * n21 * n44 + n11 * n22 * n44) * inv_det;
		const te11 = (n13 * n22 * n41 - n12 * n23 * n41 - n13 * n21 * n42 + n11 * n23 * n42 + n12 * n21 * n43 - n11 * n22 * n43) * inv_det;

		const te12 = t14 * inv_det;
		const te13 = (n13 * n24 * n31 - n14 * n23 * n31 + n14 * n21 * n33 - n11 * n24 * n33 - n13 * n21 * n34 + n11 * n23 * n34) * inv_det;
		const te14 = (n14 * n22 * n31 - n12 * n24 * n31 - n14 * n21 * n32 + n11 * n24 * n32 + n12 * n21 * n34 - n11 * n22 * n34) * inv_det;
		const te15 = (n12 * n23 * n31 - n13 * n22 * n31 + n13 * n21 * n32 - n11 * n23 * n32 - n12 * n21 * n33 + n11 * n22 * n33) * inv_det;

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
		result[15] = te15;

		return res;
	}

	compose(position, orientation, scale) {
		const result = this.matrix;
		
		const qx = orientation[0];
		const qy = orientation[1];
		const qz = orientation[2];
		const qw = orientation[3];

		const px = position[0];
		const py = position[1];
		const pz = position[2];

		const sx = scale[0];
		const sy = scale[1];
		const sz = scale[2];

		const qx2 = qx + qx;
		const qy2 = qy + qy;
		const qz2 = qz + qz;

		const qxx = qx * qx2;
		const qxy = qx * qy2;
		const qxz = qx * qz2;

		const qyy = qy * qy2;
		const qyz = qy * qz2;
		const qzz = qz * qz2;

		const qwx = qw * qx2;
		const qwy = qw * qy2;
		const qwz = qw * qz2;

		const te0 = (1.0 - (qyy + qzz)) * sx;
		const te1 = (qxy + qwz) * sx;
		const te2 = (qxz - qwy) * sx;
		const te3 = 0.0;

		const te4 = (qxy - qwz) * sy;
		const te5 = (1.0 - (qxx + qzz)) * sy;
		const te6 = (qyz + qwx) * sy;
		const te7 = 0.0;

		const te8 = (qxz + qwy) * sz;
		const te9 = (qyz - qwx) * sz;
		const te10 = (1.0 - (qxx + qyy)) * sz;
		const te11 = 0.0;

		const te12 = px;
		const te13 = py;
		const te14 = pz;
		const te15 = 1.0;

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
		result[15] = te15;

		return this;
	}

	identity() {
		const result = this.matrix;

		result[0] = 1.0;
		result[1] = 0.0;
		result[2] = 0.0;
		result[3] = 0.0;

		result[4] = 0.0;
		result[5] = 1.0;
		result[6] = 0.0;
		result[7] = 0.0;

		result[8] = 0.0;
		result[9] = 0.0;
		result[10] = 1.0;
		result[11] = 0.0;

		result[12] = 0.0;
		result[13] = 0.0;
		result[14] = 0.0;
		result[15] = 1.0;

		return this;
	}

	get determinant() {
		const matrix = this.matrix;

		const n11 = matrix[0];
		const n21 = matrix[1];
		const n31 = matrix[2];
		const n41 = matrix[3];

		const n12 = matrix[4];
		const n22 = matrix[5];
		const n32 = matrix[6];
		const n42 = matrix[7];

		const n13 = matrix[8];
		const n23 = matrix[9];
		const n33 = matrix[10];
		const n43 = matrix[11];

		const n14 = matrix[12];
		const n24 = matrix[13];
		const n34 = matrix[14];
		const n44 = matrix[15];

		const t11 = n23 * n34 * n42 - n24 * n33 * n42 + n24 * n32 * n43 - n22 * n34 * n43 - n23 * n32 * n44 + n22 * n33 * n44;
		const t12 = n14 * n33 * n42 - n13 * n34 * n42 - n14 * n32 * n43 + n12 * n34 * n43 + n13 * n32 * n44 - n12 * n33 * n44;
		const t13 = n13 * n24 * n42 - n14 * n23 * n42 + n14 * n22 * n43 - n12 * n24 * n43 - n13 * n22 * n44 + n12 * n23 * n44;
		const t14 = n14 * n23 * n32 - n13 * n24 * n32 - n14 * n22 * n33 + n12 * n24 * n33 + n13 * n22 * n34 - n12 * n23 * n34;

		const det = n11 * t11 + n21 * t12 + n31 * t13 + n41 * t14;

		return det;
	}

	makePerspective(left, right, top, bottom, near, far) {
		const matrix = this.matrix;

		const x = 2.0 * near / (right - left);
		const y = 2.0 * near / (top - bottom);

		const a = (right + left) / (right - left);
		const b = (top + bottom) / (top - bottom);
		const c = -(far + near) / (far - near);
		const d = -2.0 * far * near / (far - near);

		matrix[0] = x;
		matrix[1] = 0.0;
		matrix[2] = 0.0;
		matrix[3] = 0.0;

		matrix[4] = 0.0;
		matrix[5] = y;
		matrix[6] = 0.0;
		matrix[7] = 0.0;

		matrix[8] = a;
		matrix[9] = b;
		matrix[10] = c;
		matrix[11] = -1.0;

		matrix[12] = 0.0;
		matrix[13] = 0.0;
		matrix[14] = d;
		matrix[15] = 0.0;

		return this;
	}
}

export default Matrix4f;