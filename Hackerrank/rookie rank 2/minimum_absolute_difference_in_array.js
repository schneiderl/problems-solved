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
	var n = parseInt(readLine());
	a = readLine().split(' ');
	a = a.map(Number);
	a = a.sort(function(a,b){return a - b;} );;
	var minDiff = a[1]-a[0];

	for (var i = 2 ; i != a.length ; i++) {
		minDiff = Math.min(minDiff, a[i]-a[i-1]);
	}

	console.log(minDiff);
}
