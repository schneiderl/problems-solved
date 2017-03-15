function processData(input) {
	var n = input.length; 
	var prev = ""; 
	var curr = "";
	var c = 0;
	var newStr = ""; 

	var chars = [];

	for (var i = 0; i < n; i++) {
		curr = input.charAt(i); 
		if(i==0){
			prev = curr;
		}
		if(curr!=prev){
			var arr = new Array(2);
			arr[0] = prev;
			arr[1] = c;
			chars.push(arr);
			c= 0; 
		}

		if(i==n-1){
			if (curr == prev){
				c++;
				var arr = new Array(2);
				arr[0] = prev;
				arr[1] = c;
				chars.push(arr);
			} else{
				var arr = new Array(2);
				arr[0] = curr;
				arr[1] = 1;
				chars.push(arr);
			}
		}


		prev = curr;
		c++;
	}
	var newStr = "";
	for (var i = 0; i < chars.length; i++) {
		if(chars[i][1]%2!=0){
			newStr = newStr + chars[i][0];
		}
	}

	if(pairExists(newStr) == true){
		processData(newStr);
	} else{
		if(newStr == ""){
			console.log("Empty String");
		} else{
			console.log(newStr);
		}
	}
} 

function pairExists(str) {
	var curr = "";
	var prev = ""; 
	for (var i = 0; i < str.length; i++) {
		curr = str.charAt(i);
		if(curr==prev){
			return true; 
		}
		prev = curr;
	}
	return false; 
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
