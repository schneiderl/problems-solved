var input = require('./inputhandler.js');
var count = 0; 
calculateAllIps();
console.log("Number of Ips: " + count);
function calculateAllIps() {
	for (var i = 0; i < input.getNumberOfInputs(); i++) {
		
		var b = getBrackets(input.getNextInput(i));
		var ob = getStrWOBrackets(input.getNextInput(i));

		var pOnHyper = false;
		var pOutOfHyper = false; 
		for (var j = 0; j < b.length; j++) {
			if (splitBySubset(b[j]) != pOutOfHyper){
				pOnHyper = true;
				j = b.length; 
			}
		}

		for (var j = 0; j < ob.length; j++) {
			if (splitBySubset(ob[j])!= pOnHyper){
				pOutOfHyper = true; 
				j = ob.length; 
			}
		}


		if(pOutOfHyper == true && pOnHyper == false){
			count++
		}
	}
}

function splitBySubset(i) {
	i = i.replace("[", "");
	i = i.replace("]", "");
	for (var j = 0; j<i.length-3; j++) {
		var subset = i.substr(j,4);
		if (isPalyndrom(subset) == true){
			return true; 
		}
	}
	return false; 
}


function isPalyndrom(charset) {
	for (var i = 0; i < charset.length/2; i++) {

		if(charset.charAt(i) != charset.charAt(charset.length-i-1)){

			return false;
		}
		if(i==1){
			if (charset.charAt(0) == charset.charAt(i)){
				return false; 
			}
		}
	}
	return true; 
}

function getBrackets(ip) {
	return ip.match(/\[[a-z]*\]/g);
}

function getStrWOBrackets(ip) {
	return ip.split(/\[[a-z]*\]/g);
}


