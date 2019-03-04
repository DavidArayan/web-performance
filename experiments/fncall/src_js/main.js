import Matrix4f from './matrix4f.js';
import RandXOR from './randXOR.js';

export default class MainEXP {

	constructor() {
		this.global_rand = new RandXOR(4873);
		this.m_model = new Matrix4f();
	}

	run(iterations) {
		console.log('running iterations ' + iterations);
		let total_time = 0.0;

		let end = Date.now();
		let begin = Date.now();

		for (var i = 0; i < iterations; i++) {
			this.calculate_det();
		}

		end = Date.now();

		total_time = end - begin;
		console.log('completed time ' + total_time);
	}

	calculate_det() {
		const model_position = [0.0, 0.0, 0.0];
		const model_quaternion = [0.0, 0.0, 0.0, 0.0];
		const model_scale = [1.0, 1.0, 1.0];

		const rand = this.global_rand;
		const m_model = this.m_model;

		const model_position_x = rand.nextf(-200.0, 200.0, 100000.0);
		const model_position_y = rand.nextf(-200.0, 200.0, 100000.0);
		const model_position_z = rand.nextf(-200.0, 200.0, 100000.0);

		const model_rot_x = rand.nextf(0.0, 1.0, 100000.0);
		const model_rot_y = rand.nextf(0.0, 1.0, 100000.0);
		const model_rot_z = rand.nextf(0.0, 1.0, 100000.0);
		const model_rot_w = rand.nextf(0.0, 1.0, 100000.0);

		model_position[0] = model_position_x;
		model_position[1] = model_position_y;
		model_position[2] = model_position_z;

		let sum = 0;
		model_quaternion[3] = model_rot_w * 2.0 - 1.0;
		sum += model_quaternion[3] * model_quaternion[3];

		model_quaternion[0] = Math.sqrt(1.0 - sum) * (model_rot_x * 2.0 - 1.0);
		sum += model_quaternion[0] * model_quaternion[0];

		model_quaternion[1] = Math.sqrt(1.0 - sum) * (model_rot_y * 2.0 - 1.0);
		sum += model_quaternion[1] * model_quaternion[1];

		model_quaternion[2] = Math.sqrt(1.0 - sum) * (model_rot_z < 0.5 ? -1.0 : 1.0);

		m_model.compose(model_position, model_quaternion, model_scale);

		return m_model.determinant;
	}
}