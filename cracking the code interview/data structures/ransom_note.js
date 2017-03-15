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
	var m_temp = readLine().split(' ');
	var m = parseInt(m_temp[0]);
	var n = parseInt(m_temp[1]);
	var magazine = readLine().split(' ');
	var ransom = readLine().split(' ');

	if(searchAtMagazine(ransom, magazine)){
		console.log("Yes");
	} else{
		console.log("No");
	}
}

function searchAtMagazine(ransom, magazine) {
	for (var i = 0; i < ransom.length; i++) {
		var idx = magazine.indexOf(ransom[i]);
		if(idx==-1){
			return false;
		} else{
			magazine[idx]=undefined;
		}
	}
	return true; 
}
