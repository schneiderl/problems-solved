function processData(input) {
    var args = input.split(" ");
    var sday = parseInt(args[0]);
    var eday = args[1];
    var k = args[2];
    var c = eday-sday; 
    var count = 0;
    for (var i = 0; i <= c; i++) {
    	var re = reverse(parseInt(sday+i));
    	re = sday+i - re;
    	if(re<0){
    		re = re*-1;
    	}
    	if (re%k==0){
    		count++;
    	}
    }
    console.log(count);
} 

function reverse(n) {
	var y = n.toString();
	var r = y.split("").reverse().join("");
	var re = Number(r);
	return re; 
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
