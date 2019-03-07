import MainEXP from './main.js';

window.addEventListener('DOMContentLoaded', () => {
	(function progc() {
		console.log('Running Program!');
		
		if (!window.argv) {
			console.log('Cannot Run. Supply some arguments!');
			return;
		}

		const mainprogc = new MainEXP();

		// warmup
		console.log("Waming up the program for the JIT");
		mainprogc.run(10);

		console.log('');
		console.log('Running Program!');
		console.log('');
		// run the actual program
		mainprogc.run(parseInt(window.argv));

		console.log('Finishing Program!');
	})();
});