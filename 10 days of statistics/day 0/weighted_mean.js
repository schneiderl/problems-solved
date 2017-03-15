function processData(input) {
	var lines = input.split("\n");
	var n = lines[1].split(" ");
	var w = lines[2].split(" ");

	var s = 0;
	var d = 0;

	for (var i = 0; i < n.length; i++) {
		s = s + (parseInt(n[i])*parseInt(w[i]));
		d = d + parseInt(w[i]);
	}
	
	var r = s/d;
	console.log(parseFloat(r).toFixed(1));
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
