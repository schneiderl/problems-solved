function processData(input) {
    var lines = input.split("\n");
    var arr = lines[2].split(" ");
    var narr = lines[1].split(" ");
    var n = parseInt(lines[0]);

    var c = 0;
    var farr = [];
    for (var i = 0; i < n; i++) {
        for (var j = 1; j <= parseInt(arr[i]); j++) {
            farr[c] = parseInt(narr[i]);
            c++;
        }
    }
    console.log(processAll(farr).toFixed(1));
} 

function processAll(farr) {
    var arr = [];
    var numbers = [];
    for (var i = 0; i < farr.length; i++) {
        numbers[i] = parseInt(farr[i]); 
    }

    arr = numbers.sort(function(a,b){return a - b;} );

    var isOdd = false; 
    var dp = 0;
    if (arr.length%2 == 0){
        isOdd = true; 
    } else{
        dp = Math.ceil(arr.length/2);
    }

    var firstQuartile = [];
    var secondQuartile = [];
    for (var i = 0; i < arr.length; i++) {
        if (isOdd){
            if(i<(arr.length/2)){
                firstQuartile[i] = arr[i];
            } else{
                secondQuartile[i-arr.length/2] = arr[i];
            }
        } else{
            if(i>=dp){
                secondQuartile[i-dp] = arr[i];
            } else if(i < (dp-1)){
                firstQuartile[i] = arr[i];
            }
        }   
    }
    var fMedian = calcMedian(firstQuartile);
    var sMedian = calcMedian(secondQuartile);

    var fMedian = sMedian-fMedian; 
    return fMedian; 
}


function calcMedian(arr) {
    var median = 0; 
    for (var i = 0; i < arr.length; i++) {
        if((arr.length%2) == 0){

            if(i== ((arr.length/2)-1) || i== (arr.length/2)){
                median = median + (arr[i]/2);
            }
        } else{ 
            if(i == Math.floor(arr.length/2)){
                median = parseInt(arr[i]);
            }
        }
        
    }
    return median; 
}  


process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () {
 processData(_input);
});
