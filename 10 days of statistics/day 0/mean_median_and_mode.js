
function processData(input) {
    var lines = input.split("\n")
    var n = parseInt(lines[0]); 
    var aux = lines[1].split(" ");
    //DO not ask me why i did not used a map here
    var numbers = [];
    var repetitions = [];
    for (var i = 0; i < aux.length; i++) {
        numbers[i] = parseInt(aux[i]); 
    }
    numbers = numbers.sort(function(a,b){return a - b;} );
    mean = numbers[0];
    var mean = 0.0;
    var median = 0.0;
    var mode = 0.0;

    for (var i = 0; i < numbers.length; i++) {
        mean = mean + numbers[i];
        if((numbers.length%2) == 0){

            if(i== ((numbers.length/2)-1) || i== (numbers.length/2)){
                median = median + (numbers[i]/2);
            }
        } else{ 
            if(i == Math.floor(numbers.length/2)){
                median = numbers[i];
            }
        }
        var notFound = true; 
        for (var j = 0; j < repetitions.length; j++) {
            if (numbers[i] == repetitions[j][0]){
                notFound = false; 
                repetitions[j][1] = repetitions[j][1]+1; 
            }
        }

        if (notFound){
            var nNumber = new Array(2);
            nNumber[0] = numbers[i];
            nNumber[1] = 1;
            repetitions.push(nNumber);
        }


    }
    var idxMode = -1.0;
    var rIdx = 0;
    for (var i = repetitions.length-1; i >= 0; i--) {
        if(repetitions[i][1] >= rIdx){
            idxMode = i;
            rIdx = repetitions[i][1];
        }
    }

    mode = repetitions[idxMode][0];
    console.log(parseFloat(mean/numbers.length).toFixed(1));
    console.log(median);
    console.log(mode);

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
