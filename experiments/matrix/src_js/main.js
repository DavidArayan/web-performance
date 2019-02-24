import Matrix4f from './matrix4f.js';
import RandXOR from './randXOR.js';

export default class MainEXP {
	run(iterations) {
		console.log('Performing Iterations = ' + iterations);

		const rand = new RandXOR(42);

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

		// DATE timers
		let begin = Date.now();
		let end = Date.now();
		let end_t = Date.now();

		let begin_t = Date.now();

		for (var i = 0; i < iterations; i++) {
			// generate new random values for our matrices to keep the variance
			// going. Since the seed is always the same, this should yield consistent
			// results across multiple runs
			begin = Date.now();

			const model_position_x = rand.nextf(-2000.0, 2000.0, 100000.0);
			const model_position_y = rand.nextf(-2000.0, 2000.0, 100000.0);
			const model_position_z = rand.nextf(-2000.0, 2000.0, 100000.0);

			const camera_position_x = rand.nextf(-2000.0, 2000.0, 100000.0);
			const camera_position_y = rand.nextf(-2000.0, 2000.0, 100000.0);
			const camera_position_z = rand.nextf(-2000.0, 2000.0, 100000.0);

			const model_rot_x = rand.nextf(0.0, 1.0, 100000.0);
			const model_rot_y = rand.nextf(0.0, 1.0, 100000.0);
			const model_rot_z = rand.nextf(0.0, 1.0, 100000.0);
			const model_rot_w = rand.nextf(0.0, 1.0, 100000.0);

			const camera_rot_x = rand.nextf(0.0, 1.0, 100000.0);
			const camera_rot_y = rand.nextf(0.0, 1.0, 100000.0);
			const camera_rot_z = rand.nextf(0.0, 1.0, 100000.0);
			const camera_rot_w = rand.nextf(0.0, 1.0, 100000.0);

			end = Date.now();
			time_spent_randomness += (end - begin);

			// compute all our random positions, rotations for further operations
			begin = Date.now();

			model_position[0] = model_position_x;
			model_position[1] = model_position_y;
			model_position[2] = model_position_z;

			camera_position[0] = camera_position_x;
			camera_position[1] = camera_position_y;
			camera_position[2] = camera_position_z;

			// the rotations are computed in a specific way to ensure that the final quaternion
			// is actually a valid rotational value from a mathematical sense
			let sum = 0;
			model_quaternion[3] = model_rot_w * 2.0 - 1.0;
			sum += model_quaternion[3] * model_quaternion[3];

			model_quaternion[0] = Math.sqrt(1.0 - sum) * (model_rot_x * 2.0 - 1.0);
			sum += model_quaternion[0] * model_quaternion[0];

			model_quaternion[1] = Math.sqrt(1.0 - sum) * (model_rot_y * 2.0 - 1.0);
			sum += model_quaternion[1] * model_quaternion[1];

			model_quaternion[2] = Math.sqrt(1.0 - sum) * (model_rot_z < 0.5 ? -1.0 : 1.0);

			sum = 0;
			camera_quaternion[3] = camera_rot_w * 2.0 - 1.0;
			sum += camera_quaternion[3] * camera_quaternion[3];

			camera_quaternion[0] = Math.sqrt(1.0 - sum) * (camera_rot_x * 2.0 - 1.0);
			sum += camera_quaternion[0] * camera_quaternion[0];

			camera_quaternion[1] = Math.sqrt(1.0 - sum) * (camera_rot_y * 2.0 - 1.0);
			sum += camera_quaternion[1] * camera_quaternion[1];

			camera_quaternion[2] = Math.sqrt(1.0 - sum) * (camera_rot_z < 0.5 ? -1.0 : 1.0);

			end = Date.now();
			time_spent_randomness_assignment += (end - begin);

			// use this to re-compose all our matrices from our randomly generated data
			begin = Date.now();

			m_model.compose(model_position, model_quaternion, model_scale);
			m_camera.compose(camera_position, camera_quaternion, camera_scale);

			end = Date.now();
			time_spent_matrixcompose += (end - begin);

			// use this to invert our camera matrix (from world space to screen-space)
			begin = Date.now();

			fm_camera.invert(m_camera_inv);

			end = Date.now();
			time_spent_matrixinverse += (end - begin);

			// perform our multiplication of the matrices
			begin = Date.now();

			m_camera_inv.mul(m_model, mv);
			m_proj.mul(mv, mvp);

			end = Date.now();
			time_spent_matrixmul += (end - begin)
		}

		end_t = Date.now();

		total_time = end_t - begin_t;

		console.log('randomness (total time) ' + time_spent_randomness);
		console.log('randomness assignment (total time) ' + time_spent_randomness_assignment);
		console.log('matrix compose (total time) ' + time_spent_matrixcompose);
		console.log('matrix invert (total time) ' + time_spent_matrixinverse);
		console.log('matrix multiply (total time) ' + time_spent_matrixmul);

		console.log('total time ' + total_time);

		console.log('Finishing Program!');
	}
}