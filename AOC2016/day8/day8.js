var input = require('./inputhandler.js');

const LINES = 6;
const COLUMNS = 50;
var count = 0 ; 
var scr = new Array(LINES);
for (var i = 0; i < LINES; i++) {
	scr[i] = new Array(COLUMNS).fill(" ");
}


processScr();

for (var i = 0; i < LINES; i++) {
	var line = ""; 
	for (var j = 0; j < COLUMNS; j++) {
		line = line + scr[i][j];
		if (scr[i][j] == '*'){
			count++;
		}
	}
	console.log(line);
}
console.log(count);

function processScr() {
	for (var i = 0; i < input.getNumberOfInputs(); i++) {
		
		var cmd = input.getNextInput(i);
		if (cmd.indexOf("rect") != -1){
			cmd = cmd.replace("rect ", "");
			var idx = cmd.indexOf("x");
			var x = parseInt(cmd.substr(0, idx));
			var y = parseInt(cmd.substr(idx+1, (cmd.length - idx)));
			lightScrUp(x,y);
		} else if (cmd.indexOf("rotate row") != -1){
			cmd = cmd.replace("rotate row y=", "");
			var idx = cmd.indexOf("by");
			var y = parseInt(cmd.substr(0, (idx-1)));
			var rot = parseInt(cmd.substr((idx + 3), (cmd.length - idx)));
			rotateLine(y, rot);
		} else{
			cmd = cmd.replace("rotate column x=", "");
			var idx = cmd.indexOf("by");
			var x = parseInt(cmd.substr(0, (idx-1)));
			var rot = parseInt(cmd.substr((idx + 3), (cmd.length - idx)));
			rotateColumn(x, rot);
		} 
	}
}

function rotateColumn(x, rot) {
	var aux = JSON.parse(JSON.stringify(scr));
	for (var i = 0; i < LINES; i++) {
		var targetIndex = (i + rot) % LINES;
		scr[targetIndex][x] = aux[i][x];
	}
}

function rotateLine(y, rot){
	var aux = JSON.parse(JSON.stringify(scr));	
	for (var i = 0; i < COLUMNS; i++) {
		var targetIndex = (i + rot) % COLUMNS; 
		scr[y][targetIndex] = aux[y][i];
	}
};

function lightScrUp(x, y) {
	for (var i = 0; i < x; i++) {
		for (var j = 0; j < y; j++) {
			scr[j][i] = '*';
		}
	}
}