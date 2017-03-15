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
    arr = readLine().split(' ');
    arr = arr.map(Number);
    var b = 0;
    var z = 0;
    var l = 0;
    for (var i = arr.length - 1; i >= 0; i--) {
    	if(arr[i] > 0){
    		b++;
    	} else if (arr[i] <0) {
    		l++;
    	} else{
    		z++;
    	}
    }
    var lr = l/arr.length;
    var zr = z/arr.length;
    var br = b/arr.length;

    console.log(br);
    console.log(lr);
    console.log(zr);
}
