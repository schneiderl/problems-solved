function processData(input) {
	var input = input.split("\n");
    var v = input[0];
	var array = input[2].split(" ");

	for (var i = 0; i < array.length; i++) {
		if(v == parseInt(array[i])){
			console.log(i);
			return;  
		}
	}
} 

process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
	_input += input;
});

process.stdin.on("end", function () {
	processData(_input);
});