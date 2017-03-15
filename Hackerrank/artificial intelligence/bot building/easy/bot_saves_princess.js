function processData(input) {
    var lines = input.split('\n');
    var dimension = parseInt(lines[0]);
    var grid = [];
    for(var i = 1; i <= dimension; ++i)
    {
        grid.push(lines[i]);
    }
    displayPathtoPrincess(dimension, grid);
}
function displayPathtoPrincess(dimension, grid)
{
    var positions = findElements(dimension, grid);
    var r = positions.r;
    var p = positions.p;
    //bot moves using manhattan distance
    //calculate x: 
    var xd = p[0]-r[0];
    var yd = p[1]-r[1];
    var xdaux =0;
    var ydaux = 0;
    if (xd<0){
        xdaux = xd *-1;
    } else{
        xdaux = xd;
    }
    if (yd<0){
        ydaux = yd *-1;
    } else{
        ydaux = yd;
    }

    for (var x=0;x < xdaux; x++) {
        if (xd<0){
            console.log("LEFT");
        } 
        if (xd>0){
            console.log("RIGHT");
        }
    }

    for (var y=0; y < ydaux; y++) {
        if (yd<0){
            console.log("UP");
        } 
        if (yd>0){
            console.log("DOWN");
        }
    }
}


function findElements(dimension, grid) {
    var size = dimension*dimension; 
    var count = 0;
    var r = new Array(2);
    var p = new Array(2);
    for (var x = 0; x < dimension; x++) {
        for (var y = 0; y < dimension; y++) {
            if (grid[x][y]=="m"){
                r[0]=y;
                r[1]=x;
            }
            if (grid[x][y]=="p"){
                p[0]=y;
                p[1]=x
            }
        }
    }
    console.log(p);
    console.log(r);
    return{p:p,r:r};
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
