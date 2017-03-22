var input = require('./inputhandler.js');

var currTriangleX = 0;
var currTriangleY = 0; 
var numberOfTriangles = 0;

calcTriangleNumber();
console.log("Number of possible triangles: " + numberOfTriangles);
function calcTriangleNumber(){
	console.log(input.getNumberOfTriangles());
	for (var i = input.getNumberOfTriangles() - 1; i >= 0; i--) {
		var triangle = input.getNextTriangle(currTriangleX, currTriangleY);
		calcNextTriangle();
		var sizes = [ parseInt(triangle.side1), parseInt(triangle.side2), parseInt(triangle.side3)];
		sizes.sort(function(a,b) { return a - b; });
		console.log(sizes);
		var sizeSum = sizes[0] + sizes[1];		
		if (sizeSum > sizes[2]){
			numberOfTriangles++;
		}
	}

}

function calcNextTriangle() {
	//Weird stuff. but it works.
	currTriangleX++;
	if (currTriangleX >2){
		currTriangleX = 0; 
		currTriangleY = currTriangleY+9;
	}

}
