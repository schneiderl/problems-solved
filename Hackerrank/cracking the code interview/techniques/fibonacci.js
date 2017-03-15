function processData(input) {
	var n = parseInt(input);
	console.log(fibonacci(n));
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

function fibonacci(n) {
    var curr = 0;
	var prev = 0;
	for (var i = 0; i < n; i++) {
		if(i==1){
			curr = 1;
		}  	
		var aux = curr; 
		curr = prev+curr;
		prev = aux; 
	}
	return curr; 
}

