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
	var a = readLine();
	var b = readLine();
	var read = [];
	var c = 0; 
	for (var i = 0; i < a.length; i++) {
		if(read.indexOf(a.charAt(i))!==-1){
			read.push(a.charAt(i));
			var nA = searchNumberOfChar(a, a.charAt(i));
			var nB = searchNumberOfChar(b, a.charAt(i)); 
			var c = c+ Math.abs(nA-nB);
		}
	}

	for (var i = 0; i < b.length; i++) {
		if(read.indexOf(b.charAt(i))!==-1){
			read.push(b.charAt(i));
			var nA = searchNumberOfChar(a, b.charAt(i));
			var nB = searchNumberOfChar(b, b.charAt(i)); 
			var c = c+ Math.abs(nA-nB);
		}
	}
	console.log(c);
}

function searchNumberOfChar(string, char) {
	var c = 0; 
	for (var i = 0; i  < string.length; i++) {
		if(string.charAt(i)==char){
			c++;
		}
	}
	console.log(c);
	return c;
}
