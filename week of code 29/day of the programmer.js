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

const gregorian = [31,28,31,30,30,30,31,29,30,31,30,31];
const julian = [31,28,31,30,31,30,31,31,30,31,30,31];
function main() {
	var y = parseInt(readLine());
    // your code goes here
    var nf = false; 
    var count = 0;
    var s = 0;
    var cd = 0;
    var cm = 0;
    var cy = y;
    var chgy = false; 
    if (y< 1918){
    	var c = julian;
    	if (y%4 == 0){
    		c[1] = c[1] + 1; 
    	}
    } else if (y>1918){
    	var c = julian;
    	if (((y%4 == 0) && (y%100 != 0)) || (y%400 ==0)){
    		c[1] = c[1] + 1; 
    	}
    } else{
    	var c = julian;
    	chgy = true; 
    	c[1] = c[1]-14;
    }
    while(nf == false){
    	s = s+c[count];
    	if(s>=256){
    		cm = count+1;
    		cd = c[count] - (s-256);
    		nf = true;
    	}
    	count++
    }

    if (chgy){
    	cd = cd%gregorian[cm];
    	cm++;
    }

    if(cd<10){
    	cd = "0" + cd;
    }
    if(cm<10){
    	cm = "0" +cm; 	
    }

    console.log(cd+"."+cm+"."+cy);

}
