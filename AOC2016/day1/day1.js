var instructions = [ "L1", "R3", "R1", "L5", "L2", "L5", "R4", "L2", "R2", "R2", "L2", "R1", "L5", "R3", "L4", "L1", "L2", "R3", "R5", "L2", "R5", "L1", "R2", "L5", "R4", "R2", "R2", "L1", "L1", "R1", "L3", "L1", "R1", "L3", "R5", "R3", "R3", "L4", "R4", "L2", "L4", "R1", "R1", "L193", "R2", "L1", "R54", "R1", "L1", "R71", "L4", "R3", "R191", "R3", "R2", "L4", "R3", "R2", "L2", "L4", "L5", "R4", "R1", "L2", "L2", "L3", "L2", "L1", "R4", "R1", "R5", "R3", "L5", "R3", "R4", "L2", "R3", "L1", "L3", "L3", "L5", "L1", "L3", "L3", "L1", "R3", "L3", "L2", "R1", "L3", "L1", "R5", "R4", "R3", "R2", "R3", "L1", "L2", "R4", "L3", "R1", "L1", "L1", "R5", "R2", "R4", "R5", "L1", "L1", "R1", "L2", "L4", "R3", "L1", "L3", "R5", "R4", "R3", "R3", "L2", "R2", "L1", "R4", "R2", "L3", "L4", "L2", "R2", "R2", "L4", "R3", "R5", "L2", "R2", "R4", "R5", "L2", "L3", "L2", "R5", "L4", "L2", "R3", "L5", "R2", "L1", "R1", "R3", "R3", "L5", "L2", "L2", "R5"];

//Keep this constats here just for me to understand what i'm doing
//The solution for the second puzzle is pretty bad but.... thats life. 
const north = 0; 
const east = 1; 
const south = 2;
const west = 3; 

var currStepsX = 0; 
var currStepsY = 1;
var curr_direction = north; 

var x = 0; 
var y = 0;

var givenSteps = new Array();
var numberOfSteps = 0; 
var visitedTwiceX = undefined;
var visitedTwiceY = undefined;


calculateFinalPoint();

function calculateFinalPoint() {
	var insNumber = instructions.length;

	for (var i = 0; i < instructions.length; i++) {
		var currStep = instructions[i];
		var direction = currStep.charAt(0);
		var steps =	currStep.replace(direction, "");
		getNextDirection(direction);
		calculateSteps(steps, i); 
	}

	if (x<0){
		x = (x*-1);
	}

	if (y<0){
		y = y * -1;
	}
	var distance = y+x;

	console.log("Bunny headquarters is " + distance + " blocks away!");
}

function calculateSteps(steps, position) {
	for (var i = 0; i < steps; i++) {
		x = x + currStepsX;
		y = y + currStepsY
		givenSteps[numberOfSteps] = new Array(2);
		givenSteps[numberOfSteps][0] = x; 
		givenSteps[numberOfSteps][1] = y;
		if (visitedTwiceX == undefined){
			for (var j = 0; j < numberOfSteps; j++) {
				if ((givenSteps[numberOfSteps][0] == givenSteps[j][0] ) && ( givenSteps[numberOfSteps][1] == givenSteps[j][1])){
				visitedTwiceX =  givenSteps[j][0];
				visitedTwiceY =  givenSteps[j][1];				
				if ( visitedTwiceY < 0 ) { visitedTwiceY = visitedTwiceY * -1};
				if ( visitedTwiceX < 0 ) { visitedTwiceX = visitedTwiceX * -1};
				console.log("The distance for the first point visited twice is: " + (visitedTwiceX+visitedTwiceY));				
			}
		}
	}
	numberOfSteps++;
}
}



function getNextDirection(direction) {
	if (direction == "L"){
		curr_direction = curr_direction -1; 
		if ( curr_direction == -1){
			curr_direction = west; 
		}
	} else {
		curr_direction = curr_direction + 1; 
		if ( curr_direction == 4){
			curr_direction = north; 
		}
	}
	switch (curr_direction) {
		case north: currStepsY = 1; currStepsX = 0; break; 
		case east: currStepsY = 0; currStepsX = 1; break;
		case south: currStepsY = -1; currStepsX = 0; break;
		case west: currStepsY = 0; currStepsX = -1; break;
	}
}



