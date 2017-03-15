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
    c = readLine().split(' ');
    c = c.map(Number);

    var p = [];
    var idx = [];


    for (var i = 0; i < c.length; i++) {
    	var x = idx.indexOf(c[i]);
    	
    	if ( x == -1){
    		idx.push(c[i]);
    		p.push(1);
    	} else{ 
    		p[x] = parseInt(p[x]) + 1; 
    	}
    }
    
    var s = 0 ;
    for (var i = 0; i <p.length; i++) {		
    	s = s + Math.floor(p[i]/2);
    }

    console.log(s);
}
