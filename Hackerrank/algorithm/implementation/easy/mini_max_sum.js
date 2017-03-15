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
    var a_temp = readLine().split(' ');
    var a = parseInt(a_temp[0]);
    var b = parseInt(a_temp[1]);
    var c = parseInt(a_temp[2]);
    var d = parseInt(a_temp[3]);
    var e = parseInt(a_temp[4]);
    var lower = 0;
    var bigger = 0;
    var sum = 0;
    for (var i = 0; i <= 4; i++) {
        sum = sum + parseInt(a_temp[i]);
        if(parseInt(a_temp[i]) > bigger){
            bigger = parseInt(a_temp[i]);
        }
    }
    lower = bigger; 
    for (var i = 0; i <= 4; i++) {
        if(lower > parseInt(a_temp[i])){
            lower = parseInt(a_temp[i]);
        }
    }


    console.log((sum-bigger) + " " + (sum-lower));

}
