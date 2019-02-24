class RandXOR {
	constructor(seed) {
		this.seed = Math.abs(seed) | 0;
	}

	next() {
		let seed = this.seed;

		seed ^= (seed << 13);
		seed ^= (seed >> 7);
		seed ^= (seed << 17);
		seed = Math.abs(seed);

		this.seed = seed | 0;

		return this.seed;
	}

	nextf(min, max, dev) {
		const lmin = (min * dev) | 0;
		const lmax = (max * dev) | 0;
		const rand_number = this.nexti(lmin, lmax);
		const rand_number_d = rand_number / dev;

		return rand_number_d;
	}

	nexti(min, max) {
		if (min > max) {
			return this.nexti(max, min);
		}

		if (min == max) {
			return min;
		}

		const rand_num = this.next();

		return (rand_num % (max + 1 - min)) + min;
	}
}

export default RandXOR;