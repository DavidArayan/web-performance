import MainEXP from './main.js';

window.addEventListener('DOMContentLoaded', () => {
	(function progc() {
		if (!window.argv) {
			console.log("Please provide a program argument such as ?argv=1000");
			return;
		}

		new MainEXP().run(parseInt(window.argv));
	})();
});