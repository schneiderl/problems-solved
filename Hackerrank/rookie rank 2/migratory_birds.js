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
	var n = parseInt(readLine());
	types = readLine().split(' ');
	types = types.map(Number);
    // your code goes here
    var b = new Array(5).fill(0); 

    for (var i = 0; i < types.length; i++) {
    	b[parseInt(types[i]) -1] = b[parseInt(types[i]) -1] +1;
    }

    var greater = 0;
    for (var i = b.length-1; i >=0; i--) {
    	if(b[i] >= b[greater]){
    		greater = i;
    	}

    }

    console.log(greater+1);


}
