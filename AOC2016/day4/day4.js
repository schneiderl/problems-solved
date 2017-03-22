var input = require('./inputhandler.js'); 
var currRoom = 0; 
var alphabet = ["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"];

calcAllRooms();

function calcAllRooms() {
	var sum = 0; 
	for (var i = 0; i < input.getNumberOfRooms(); i++) {
		//sum = sum + 
		var sumAux = parseInt(calcCurrRoom(input.getRoom(i)));
		sum = sum + sumAux;
	}
	console.log(sum);
}

//decrypt("qzmt-zixmtkozy-ivhz-", 343)

function decrypt(room, id) {
	var numberOfChanges = id % alphabet.length;
	for (var i = 0 ; i < room.length; i++) {
		var idx = alphabet.indexOf(room[i]);
		if (idx != -1){
			idx = idx + id;
			idx = idx % alphabet.length;
			room = room.substr(0, i) + alphabet[idx] +  room.substr(i + 1);
		}
	}
	var decrypted = room.replace(new RegExp('-', 'g'), " ");
	return decrypted;
}


function calcCurrRoom(room){
	var encryption = room;
	var matches = [];
	var addedMatches = 0; 
	var sectorid = getSectorId(room);
	var checksum = getChecksum(room);

	encryption = encryption.replace(sectorid, "");
	encryption = encryption.replace(checksum, "");
	console.log("Message:"+decrypt(encryption, parseInt(sectorid))+" ID:" + sectorid);
	for (var i = 0; i < alphabet.length; i++) {
		var regex = new RegExp(alphabet[i], 'g');
		var reg = room.match(regex);
		if (reg != null ){
			var matched = {char:alphabet[i], number:reg.length}; 
			matches[addedMatches] = matched; 
			addedMatches++; 
		}
	}

	matches = sortMatches(matches);
	//console.log(checksum);
	if (isCorrect(matches, checksum)){
		return sectorid;
	} else{
		return 0; 
	}

}

function sortMatches(matches){
	var wmatches = matches.sort(sortByNumberAndChar);
	return wmatches; 
}

function sortByNumberAndChar(a,b){

	if (a.number < b.number)
		return 1;
	if (a.number > b.number)
		return -1;
	if (a.number == b.number){
		if (a.char < b.char)
			return -1;
		if (a.char > b.char)
			return 1;
	}
	return 0;
}

function isCorrect(matches, checksum){
	var chk = checksum;
	chk = chk.replace("[", "");
	for (var i = 0; i < 5; i++) {
		//console.log(matches[i].char);
		//console.log(chk.charAt(i));
		if (matches[i].char != chk.charAt(i)){
			return false;
		}
	}
	return true; 
}



function getSectorId(room) {
	var sectorId = room.match(/\d{3}/)[0];
	return sectorId;
}

function getChecksum(room){
	var checksum = room.match(/\[[a-z]{5}\]/)[0];
	return checksum; 
}

function getNextRoom() {
	currRoom++;
	return input.getRoom(currRoom-1);
}