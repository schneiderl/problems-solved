function processData(input) {
    //Enter your code here
    var lines = input.split("\n");
    var arr = lines[1].split(" ");
    var n = parseInt(lines[0]);
    var numbers = [];
    for (var i = 0; i < arr.length; i++) {
        numbers[i] = parseInt(arr[i]); 
    }
    numbers = numbers.sort(function(a,b){return a - b;} );
    arr = numbers;
    var isOdd = false; 
    var dp = 0;
    if (n%2 == 0){
        isOdd = true; 
    } else{
        dp = Math.ceil(n/2);
    }

    var firstQuartile = [];
    var secondQuartile = [];
    for (var i = 0; i < n; i++) {
        if (isOdd){
            if(i<(n/2)){
                firstQuartile[i] = arr[i];
            } else{
                secondQuartile[i-n/2] = arr[i];
            }
        } else{
            if(i>=dp){
                secondQuartile[i-dp] = arr[i];
            } else if(i < (dp-1)){
                firstQuartile[i] = arr[i];
            }
        }   
    }

    console.log(calcMedian(firstQuartile));
    console.log(calcMedian(arr));
    console.log(calcMedian(secondQuartile));
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
