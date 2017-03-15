	process.stdin.resume();
	process.stdin.setEncoding('ascii');

	var input_stdin = "";
	var input_stdin_array = "";
	var input_currentline = 0;

	process.stdin.on('data', function (data) {
		input_stdin += data;
	});

	process.stdin.on('end', function () {
		input_stdin_array = input_stdin.split("\n");
		main();    
	});

	function readLine() {
		return input_stdin_array[input_currentline++];
	}

	/////////////// ignore above this line ////////////////////
	var c = 0;
	var f = 0; 
	function main() {
		var s = readLine();

		var msg = s.replace(" ", ""); 
		var g = getBestFitGrid(msg);
		g = fillGrid(g, msg);
		printGrid(g);
	}

	function printGrid(g) {
		var str = "";

		for (var i = 0; i < c; i++) {
			var partStr = "";
			for (var j = 0; j < f; j++) {
				if (g[j][i] != undefined){
					partStr = partStr + g[j][i];
				}
			}
			if (str == ""){
				str = partStr;
			} else{
				str = str + " " + partStr;
			}
		}
		console.log(str);

	}

	function fillGrid(g, msg) {
		var count = 0;
		for (var i = 0; i < f; i++) {
			for (var j = 0; j < c; j++) {
				if((count) < msg.length){
					g[i][j] = msg.charAt(count);
				}
				count++;
			}
		}
		return g;
	}

	function getBestFitGrid(msg) {
		c = Math.ceil(Math.sqrt(msg.length)); 
		f = Math.floor(Math.sqrt(msg.length));

		var neededRecalc = true; 

		while(neededRecalc){
			if ((c*f) < msg.length){
				f++;
			} else{
				neededRecalc = false; 
			}
		}

		var g = new Array(f);
		for (var i = 0; i < f; i++) {
			g[i] = new Array(c);
		}

		return g; 

	}