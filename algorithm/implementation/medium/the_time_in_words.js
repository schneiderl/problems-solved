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

const hours = ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve" ];
const mins = ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "twenty one", "twenty two", "twenty three", "twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine"];
const b = [" o' clock", " minutes past ", "half past ", "quarter to ", " minutes to ", "quarter past "];

function main() {
	var h = parseInt(readLine());
	var m = parseInt(readLine());
	var currHour = "";
	var currMin = "";
	if ( m > 30){
		currHour = hours[h];
	} else{ 
		currHour = hours[h-1];
	}
	var s = "";
	if (m == 0){
		s = currHour + b[0];
	} else if (m >0 && m<30 ){
		if (m == 15){
			s = b[5] + currHour;
		} else{
			s = mins[m-1] + b[1] + currHour;
		}
	} else if (m == 30){
		s = b[2] + currHour;
	} else if (m == 45){
		s = b[3] + currHour;
	} else{
		var currPos = (m-60) * -1 ;
		s = mins[currPos-1] + b[4] + currHour;
	}

	console.log(s);

}

