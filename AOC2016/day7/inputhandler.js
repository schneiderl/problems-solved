var input = [ "rhamaeovmbheijj[hkwbkqzlcscwjkyjulk]ajsxfuemamuqcjccbc",
"tivudfusgnewzshs[mausfjbgxmyibin]yponuityptavbhekrlg[qeyafuevtlqemtfa]owtdxadrwwbxbrkl[obfcyxbifipwhduubu]mjocivgvrcbrllso" ]; 

module.exports.getNumberOfInputs = function(){
  var n = input.length
  return n;
}
module.exports.getNextInput = function(pos){
	return input[pos];
}
