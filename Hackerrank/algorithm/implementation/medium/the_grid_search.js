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
    var t = parseInt(readLine());
    for(var a0 = 0; a0 < t; a0++){
        var R_temp = readLine().split(' ');
        var R = parseInt(R_temp[0]);
        var C = parseInt(R_temp[1]);
        var G = [];
        for(var G_i = 0; G_i < R; G_i++){
           G[G_i] = readLine().replace("\r", "");
           G[G_i] = G[G_i].split("");
       }
       var r_temp = readLine().split(' ');
       var r = parseInt(r_temp[0]);
       var c = parseInt(r_temp[1]);
       var P = [];
       for(var P_i = 0; P_i < r; P_i++){
           P[P_i] = readLine().replace("\r", "");
           P[P_i] = P[P_i].split("");
       }
       var found = false; 
       for (var i = 0; i < R; i++) {
           for (var j = 0; j < C; j++) {
            if(G[i][j] == P[0][0]){
                if(lookArround(i, j, r, c, G, P)){
                    i = R; j = C; 
                    console.log("YES");
                    found = true; 
                }
            } 
        }
    }
    if(!found){
        console.log("NO"); 
    }
}
}

function lookArround(idxi, idxj, r, c, G, P) {
    for (var i = idxi; i < idxi+r; i++) {
        for (var j = idxj; j < idxj+c; j++) {
            if(G[i][j] != P[i-idxi][j-idxj]){
                return false; 
            }
        }
    }


return true; 
}