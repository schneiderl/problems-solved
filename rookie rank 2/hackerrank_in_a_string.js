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
const hs = ["h", "a", "c", "k", "e", "r", "r", "a", "n", "k"];
function main() {
    var q = parseInt(readLine());
    var c = 0; 
    for(var a0 = 0; a0 < q; a0++){
        var s = readLine();
        for (var i = 0; i < s.length; i++) {
        	if (s.charAt(i) == hs[c]){
        		c++;
        	}
        }
        if (c==10){
        	console.log("YES");
        } else{
        	console.log("NO");
        }
        c = 0;
    }

}
