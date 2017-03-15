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
    const space = " ";
    const tag = "#"; 
    var count = 1;

    while (count <= n){
    	var currLine = "";
    	for (var i = 0; i < n-count; i++) {
    		currLine = currLine + space; 
    	}
    	for (var i = 0; i < count; i++) {
    		currLine = currLine + tag; 
    	}
    	console.log(currLine);
    	count++;
    }
}
