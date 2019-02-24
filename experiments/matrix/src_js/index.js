import MainEXP from './main.js';

window.addEventListener('DOMContentLoaded', () => {
	(function progc() {
		if (!window.argv) {
			console.log('Cannot Run. Supply some arguments!');
			return;
		}

		new MainEXP().run(parseInt(window.argv));
	})();
});