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

	const cons = ["b","c","d","f","g","h","j","k","l","m","n","p","q","r","s","t","v","w","x","z"];
	const vog = ["a", "e", "i", "o", "u"];

	var c = 0; 
	function main() {
		var n = parseInt(readLine());
		for (var i = 1; i <= n; i++) {
			calcWord(true, i, "");
			calcWord(false, i, "");	
		}
		console.log(c);

	}

	function calcWord(startCons, n, word) {
		if(startCons){
			for (var i = 0; i < cons.length; i++) {
				var nword = word + cons[i];
				c++;
				if(nword.length==n){
					//console.log(nword);
				} else{
					calcWord(!startCons, n, nword);
				}
			}
		} else{
			for (var i = 0; i < vog.length; i++) {
				var nword = word + vog[i];
				c++
				if(nword.length==n){
					//console.log(nword);
				} else{
					calcWord(!startCons, n, nword);
				}
			}

		}
	}
