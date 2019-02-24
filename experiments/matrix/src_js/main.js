import Matrix4f from './matrix4f.js';
import RandXOR from './randXOR.js';

export default class MainEXP {
	run(iterations) {
		console.log('Performing Iterations = ' + iterations);

		const random = new RandXOR(42);

		// primary matrices, initialized to the identity matrix
		const m_model = new Matrix4f();
		const m_camera = new Matrix4f();
		const m_proj = new Matrix4f();

		// make our mock perspective matrix
		m_proj.makePerspective(50.0, 800.0 / 600.0, 1.0, 500000.0);

		// our operation buffers, these are here so we don't re-allocate
		// all the time and just measure raw compute performance
		const m_camera_inv = new Matrix4f();
		const mv = new Matrix4f();
		const mvp = new Matrix4f();

		// our position, quaternion, scale values which we will use to
		// compose our matrices
		const model_position = [0.0, 0.0, 0.0];
		const model_quaternion = [0.0, 0.0, 0.0, 0.0];
		const model_scale = [100.0, 100.0, 100.0];

		const camera_position = [0.0, 0.0, 0.0];
		const camera_quaternion = [0.0, 0.0, 0.0, 0.0];
		const camera_scale = [1.0, 1.0, 1.0];

		// timer variables
		let time_spent_randomness = 0.0;
		let time_spent_randomness_assignment = 0.0;
		let time_spent_matrixinverse = 0.0;
		let time_spent_matrixmul = 0.0;
		let time_spent_matrixcompose = 0.0;
		let total_time = 0.0;

		for (var i = 0; i < iterations; i++) {

		}

		console.log('randomness (total time) ' + time_spent_randomness);
		console.log('randomness assignment (total time) ' + time_spent_randomness_assignment);
		console.log('matrix compose (total time) ' + time_spent_matrixcompose);
		console.log('matrix invert (total time) ' + time_spent_matrixinverse);
		console.log('matrix multiply (total time) ' + time_spent_matrixmul);

		console.log('total time ' + total_time);

		console.log('Finishing Program!');
	}
}