function processData(input) {

    console.log(reData(input, 1, 5, 0));

} 
function reData(nMax, nCurr, p, s) {
	var cp = p; 
	cp = Math.floor(cp/2);
	var sn = cp + s; 
	cp = cp*3;
	if (nMax == nCurr){
		return sn; 
	} else{
		return(reData(nMax, nCurr+1, cp, sn));
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
	