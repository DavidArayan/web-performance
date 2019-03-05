export default class MainEXP {

	constructor(global_module) {
		this.global_module = global_module;
	}

	run(iterations) {
		const global_module = this.global_module;
		
		global_module._alloc_buffers();
		console.log('running iterations ' + iterations);
		let total_time = 0.0;
		let value = 0;

		let end = Date.now();
		let begin = Date.now();

		for (var i = 0; i < iterations; i++) {
			value += global_module._calculate_det();
		}

		end = Date.now();

		total_time = end - begin;
		console.log('completed time ' + total_time);

		// this gets printed so JIT does not get rid of
		// our process
		console.log('final value ' + value);
		global_module._free_buffers();
	}
}