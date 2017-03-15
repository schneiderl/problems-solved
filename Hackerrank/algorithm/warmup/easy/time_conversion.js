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
	var time = readLine();
	var hour = time.substr(0,2);
	var mins = time.substr(3,2);
	time = time.replace(hour, "");
	var partOfTheDay = time.substr(time.length-2, time.length);
	time = time.replace(partOfTheDay, "");
	var hourInt = parseInt(hour);
	if (partOfTheDay == "AM" && hourInt == 12){
		hourInt = hourInt + 12;
	} else if (partOfTheDay == "PM" && hourInt != 12){
		hourInt = hourInt +12;
	}

	if (hourInt == 24){
		hourInt ="00";
	}
	if (parseInt(hourInt) < 10 && parseInt(hourInt) > 0){
		hourInt = "0" + hourInt;
	}
	var currTime = hourInt + time;   
	console.log(currTime);
}
