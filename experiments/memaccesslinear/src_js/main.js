import RandXOR from './randXOR.js';

export default class MainEXP {
	run(numbers) {
		const rand = new RandXOR(42);

		const source_access = new Int32Array(numbers * 2);
		const destination = new Int32Array(numbers);

		let total_time = 0.0;

		let end = Date.now();
		let begin = Date.now();

		for (var i = 0; i < numbers * 2; i++) {
			source_access[i] = rand.nexti(0, 200000);
		}

		end = Date.now();

		total_time = end - begin;
		console.log('assign random values time ' + total_time);

		begin = Date.now();

		var j = 0;

		for (var i = 0; i < (numbers * 2); i+=2) {
			const dst_1 = source_access[i];
			const dst_2 = source_access[i + 1];

			destination[j] = dst_1 + dst_2;

			j++;
		}

		end = Date.now();

		total_time = end - begin;
		console.log('linear memory access ' + total_time);
		console.log('access first = ' + source_access[0] + ' last = ' + source_access[(numbers * 2) - 1]);
		console.log('destination first = ' + destination[0] + ' last = ' + destination[numbers - 1]);

		return destination;
	}
}