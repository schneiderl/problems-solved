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
    var T = parseInt(readLine());
    for(var a0 = 0; a0 < T; a0++){
        var n = parseInt(readLine());
        q = readLine().split(' ');
        q = q.map(Number);
        // your code goes here
        var bribes = 0; 
        if (isTooChaotic(q, n) == true){
            console.log("Too chaotic");
        } else{ 

            var notSortedYet = true; 
            while(notSortedYet){
                notSortedYet = false; 
                for (var i = 0; i < (n-1); i++) {
                    if(q[i] > q[i+1]){
                        var aux = q[i]; 
                        q[i] = q[i+1];
                        q[i+1] = aux;
                        bribes++; 
                        notSortedYet = true; 
                    }
                }
            }
            console.log(bribes);
        }
        
    }

}

function isTooChaotic(q, n) {
    for (var i = 0; i < n; i++) {
        if(q[i] > (i+3)){
            return true;
        }

    }
}
