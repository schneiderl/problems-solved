var input = require('./inputhandler.js');
var alphabet = ["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"];
var repetitions = new Array(alphabet.length).fill(0);
console.log(repetitions);
var message = "";

calculateMessage();
console.log(message);
function calculateMessage() {
	for (var x = 0; x < 8; x++) {
		for (var y = 0; y < input.getNumberOfInputs(); y++) {
			var currChar = input.getNextInput(x, y);
			var idx = alphabet.indexOf(currChar);
			repetitions[idx] = repetitions[idx] + 1;
		}
		message = message + alphabet[getMostCommonPosition()];
		repetitions = new Array(alphabet.length).fill(0); 
	}
}

function getMostCommonPosition() {
	var lowerValue = 0;

	for (var i = repetitions.length - 1; i >= 0; i--) {
		if (parseInt(repetitions[i]) < repetitions[lowerValue]){
			lowerValue = i; 
		}
	}
	return lowerValue; 
}
