function processData(input) {
    //Enter your code here
    var input = input.split("\n");
    var f = input[0].split(" ");
    var n = f[0]; var k = f[1]; 
    var c = input[2];
    var items = input[1].split(" ");

    var s = 0;

    for (var i = 0; i < items.length; i++) {
    	if(i!=k){
    		s = s + parseInt(items[i]); 
    	}
    }

    if (s/2 == c){
    	console.log("Bon Appetit");
    } else {
    	var correct =( c - (s/2) );

    	console.log(correct);
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
