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
	A = readLine().split(' ');
	A = A.map(Number);

	var read = [];
	var idxs = [];
	var count = 0;
	for (var i = 0; i < n; i++) {
		if(read.indexOf(A[i])==-1){
			var currChar = A[i];
			var foundAtIdxs = [];
			foundAtIdxs.push(i);
			for (var j = i+1; j < n; j++) {
				if(A[j] == A[i]){
					foundAtIdxs.push(j);
				}
			}

			var min = Number.MAX_VALUE; 
			if(foundAtIdxs.length != 1){
				for (var j = 0; j < foundAtIdxs.length-1; j++) {
					var insanity = Math.abs(parseInt(foundAtIdxs[j])-parseInt(foundAtIdxs[j+1]));
					if(insanity < min){
						min = insanity;
					}
				}

				read.push(min);
				count++;
			}
		} 
	}
	if(read.length != 0){
		var min = Number.MAX_VALUE;
		for (var i = 0; i < count; i++) {
			if(min > parseInt(read[i])){
				min = parseInt(read[i]);
			}
		}

		console.log(min);
	} else{
		console.log("-1");
	}

}
