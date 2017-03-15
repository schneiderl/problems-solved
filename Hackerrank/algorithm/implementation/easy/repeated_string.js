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

function main() {
	var s = readLine();
	var n = parseInt(readLine());

	var f = Math.floor(n/s.length);
	var nOfA = 0; 
	for (var i = 0; i < s.length; i++) {
		if(s.charAt(i) == "a"){
			nOfA++;
		}
	}
	nOfA = nOfA * f; 
	var rem = n - (f*s.length);
	//Those two loops are used to avoid the need of building the actual string and looping it 
	for (var i = 0; i < rem; i++) {
		if(s.charAt(i) == "a"){
			nOfA++;
		}
	}
    
console.log(nOfA);
}
