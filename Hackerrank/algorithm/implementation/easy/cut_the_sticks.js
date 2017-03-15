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
	arr = arr.sort(function(a,b){return a - b;} );
	var calc = true; 
	var count = arr.length;

	while(calc){
		if (count!=0){ //This makes no sense. 
					   //sorry =)
			console.log(count);
		}
		var curr_lowest = -1;
		for (var i = 0; i < arr.length; i++) {
			if(count!=0 && curr_lowest == -1 && arr[i] != 0){
				curr_lowest =arr[i];
			}

			if(curr_lowest!= -1){
				if((arr[i]-curr_lowest)<=0){
					arr[i] = 0;
					count--;
				} else{
					arr[i] = arr[i]-curr_lowest;
				}
			}
		}
		if (curr_lowest == -1){
			calc=false;
		}
	}


}
