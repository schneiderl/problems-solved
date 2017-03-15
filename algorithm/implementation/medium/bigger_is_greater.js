process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () {
    processData(_input);
});

function processData(input) {
    var lines = input.split("\n");
    var n = parseInt(lines[0]);

    for (var i = 1; i <= n; i++) {
        var arr = lines[i].split("");
        if(nextPermutation(arr) == false){
            console.log("no answer");
        } else{
            var newStr = "";
            for (var j = 0; j < arr.length; j++) {
                newStr = newStr + arr[j];
            }

            console.log(newStr);
        }
    }
}

function nextPermutation(array) {
    var i = array.length - 1;
    while (i > 0 && array[i - 1] >= array[i])
        i--;
    if (i <= 0)
        return false;
    var j = array.length - 1;
    while (array[j] <= array[i - 1])
        j--;
    var temp = array[i - 1];
    array[i - 1] = array[j];
    array[j] = temp;
    j = array.length - 1;
    while (i < j) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i++;
        j--;
    }
    return true;
}