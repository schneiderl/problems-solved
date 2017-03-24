const input = ["rect 1x1" ,"rotate column x=0 by 4"];
//const input = ["rect 3x2", "rotate column x=1 by 1", "rotate row y=0 by 4"];
module.exports.getNumberOfInputs = function(){
  var n = input.length
  return n;
}
module.exports.getNextInput = function(pos){
	return input[pos];
}

