function processData(input) {
    var lines = input.split("\n");
    var arr = lines[1].split(" ");
    var farr = [];
    for (var i = 0; i < arr.length; i++) {
    	farr[i] = parseInt(arr[i]);
    }

    var mean = calcMean(farr); 
    var sqdDistance = squaredDistance(farr, mean);
    var stdDev = Math.sqrt(sqdDistance/farr.length);
    console.log(stdDev.toFixed(1));
} 

function squaredDistance(farr, mean) {
	var sqdDistance = 0;
	for (var i = 0; i < farr.length; i++) {
		sqdDistance = sqdDistance + Math.pow((farr[i] - mean), 2);
	}

	return sqdDistance; 
}
function calcMean(farr) {
	var mean = 0;

	for (var i = 0; i < farr.length; i++) {
		mean = mean + farr[i];
	}
	mean = mean/farr.length;
	return mean;

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
