function processData(input) {
	var lines = input.split("\n");
	var n = parseInt(lines[0]);
	var arr = lines[1].split(" ");
	arr = arr.map(Number);
	var auxArr = [];
	var auxCount = [];
	for (var i = 0; i < n; i++) {
		var idx = auxArr.indexOf(arr[i]);
		if(idx==-1){
			auxArr.push(arr[i]);
			auxCount.push(1);
		} else{
			auxCount[idx] = auxCount[idx]+1;
		}
	}
	var bigger = Number.MIN_VALUE; 
	for (var i = 0; i < auxArr.length; i++) {
		if(auxCount[i] > bigger){
			bigger = auxCount[i];
		}
	}
	console.log(arr.length-bigger);
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
