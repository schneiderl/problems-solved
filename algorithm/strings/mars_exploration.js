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
    var S = readLine();
    const SOS = "SOS"; 
    var c =0;
    for (var i = 0; i < S.length; i++) {
    	if(s.charAt(i) != SOS.charAt(i%3)){
    		c++; 
    	}
    }
    console.log(c);
}
