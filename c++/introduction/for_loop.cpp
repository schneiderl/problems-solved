#include <iostream>
#include <cstdio>
using namespace std;

int main() {
// Complete the code.
	int a;
	int b; 
	cin >> a;
	cin >> b;
   // sorry
	for(int n = a; n <= b; n++){
		if (n > 9){ 
			if (n%2 == 0){
				cout << "even" << endl;
			} else{
				cout << "odd" << endl; 
			}

		} else{
			if( n == 1){
				cout << "one" << endl; 
			} 
			if (n == 2){
				cout << "two" << endl; 
			}
			if (n == 3){
				cout << "three" << endl; 
			}
			if(n == 4){
				cout << "four" << endl; 
			}
			if(n == 5){
				cout << "five" << endl; 
			}
			if(n == 6){
				cout << "six" << endl; 
			}
			if(n == 7){
				cout << "seven" << endl; 
			}	
			if(n == 8){
				cout << "eight" << endl; 
			}
			if(n == 9){
				cout << "nine" << endl; 
			}
		}
	}

	return 0;
}
