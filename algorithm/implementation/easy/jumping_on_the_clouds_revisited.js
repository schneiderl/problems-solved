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
	var n_temp = readLine().split(' ');
	var n = parseInt(n_temp[0]);
	var k = parseInt(n_temp[1]);
	c = readLine().split(' ');
	c = c.map(Number);

	var relevant = true;
	var energy = 100;
	var cc = 0;
    var count = 0;
	while(relevant){

		if(cc==0 & count!=0){
			relevant = false;
		} else{
            count++;
			cc = (cc + k)%n;
			energy = energy -1;
			if(c[cc] == 1){
				energy = energy-2; 
			}
		}

	}

	console.log(energy);

}
