#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
	int n;
	cin >> n;

	if (n > 9){
		cout << "Greater than 9" << endl; 
	} else{
		//I must say I almost cried doing this
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
	return 0;
}
