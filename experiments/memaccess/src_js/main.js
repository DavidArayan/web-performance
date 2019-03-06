import RandXOR from './randXOR.js';

export default class MainEXP {
	run(numbers) {
		const rand = new RandXOR(42);

		const source_access = new Int32Array(numbers);
		const source_lut = new Int32Array(numbers * 2);
		const destination = new Int32Array(numbers);

		let total_time = 0.0;

		let end = Date.now();
		let begin = Date.now();

		for (var i = 0; i < numbers * 2; i++) {
			source_lut[i] = rand.nexti(0, numbers - 1);
		}

		for (var i = 0; i < numbers; i++) {
			source_access[i] = rand.nexti(0, 200000);
		}

		end = Date.now();

		total_time = end - begin;
		console.log('assign random values time ' + total_time);

		begin = Date.now();

		for (var i = 0; i < (numbers * 2); i+=2) {
			const src_1 = source_lut[i];
			const src_2 = source_lut[i + 1];

			const dst_1 = source_access[src_1];
			const dst_2 = source_access[src_2];

			destination[src_1] = dst_1 + dst_2;
		}

		end = Date.now();

		total_time = end - begin;
		console.log('random memory access ' + total_time);
		console.log('access first = ' + source_access[0] + ' last = ' + source_access[numbers - 1]);
		console.log('destination first = ' + destination[0] + ' last = ' + destination[numbers - 1]);

		return destination;
	}
}