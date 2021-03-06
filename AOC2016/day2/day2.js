const instructions = [ "RRR","LUUU","LLR","DLU","DUD"];

// const instructions = ["ULL", 
// 					  "RRDDD",
// 					  "LURDL",
// 					  "UUUUD"]

var keypad = new Array(5); 
keypad[0] = ["*", "*", "1", "*", "*"];
keypad[1] = ["*", "2", "3", "4", "*"];
keypad[2] = ["5", "6", "7", "8", "9"];
keypad[3] = ["*", "A", "B", "C", "*"];
keypad[4] = ["*", "*", "D", "*", "*"];
var movementX = 0;
var movementY = 0;
var currKeyX = 0;
var currKeyY = 2;


calculateCode();

function calculateCode(){
	for (var i = 0; i < instructions.length; i++) {
		var ins = instructions[i];
		for (var j = 0; j < ins.length; j++) {
			var currIns = ins.charAt(j);
			getNextDirection(currIns);
			getNextKey();
		}
		console.log(keypad[currKeyY][currKeyX]);
	}
}

function getNextKey() {
	currKeyY = currKeyY + movementY;
	currKeyX = currKeyX + movementX;


	if (currKeyY < 0 || currKeyY >4 || keypad[currKeyY][currKeyX] == "*"){
		currKeyY = currKeyY - movementY;
	}
	if (currKeyX < 0 || currKeyX > 4 || keypad[currKeyY][currKeyX] == "*"){
		currKeyX = currKeyX - movementX;
	}
}

function getNextDirection(direction) {
	switch (direction) {
		case 'R': movementX = 1; movementY = 0; break; 
		case 'L': movementX = -1; movementY = 0; break;
		case 'U': movementX = 0; movementY = -1; break;
		case 'D': movementX = 0; movementY = 1; break;
	}
}