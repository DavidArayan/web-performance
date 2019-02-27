import RandXOR from './randXOR.js';

export default class MainEXP {
	run(numbers) {
		const rand = new RandXOR(42);

		const values = new Int32Array(numbers);

		let total_time = 0.0;

		let end = Date.now();
		let begin = Date.now();

		for (var i = 0; i < numbers; i++) {
			values[i] = rand.nexti(-200000, 200000);
		}

		end = Date.now();

		total_time = end - begin;
		console.log('assign random values time ' + total_time);

		const cmp = function(a, b) {
			return a - b;
		};

		begin = Date.now();

		values.sort(cmp);

		end = Date.now();

		total_time = end - begin;
		console.log('sort time ' + total_time);

		return values;
	}
}