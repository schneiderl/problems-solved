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

using namespace std;
int max(int a, int b) { return (a > b)? a : b; }
int getMaxHourglassSum(int currRow, int currColl, int maxRow,int maxColl, int arr[6][6]){
	if(currRow == maxRow-2 || currColl == maxColl-2){
		return INT_MIN;
	}
	int curr = 0; 
	for (int i = 0; i < 3; ++i){
		curr = curr + arr[currColl][currRow+i];
		curr = curr + arr[currColl+2][currRow+i];
	}
	curr = curr+arr[currColl+1][currRow+1];
	return max(getMaxHourglassSum(currRow+1, currColl, maxRow, maxColl, arr), max(getMaxHourglassSum(currRow, currColl+1, maxRow, maxColl, arr), curr));
}

int main(){
    int arr[6][6];
    for(int arr_i = 0;arr_i < 6;arr_i++){
       for(int arr_j = 0;arr_j < 6;arr_j++){
          cin >> arr[arr_i][arr_j];
       }
    }
    cout<<getMaxHourglassSum(0,0,6,6,arr)<<endl; 
    return 0;
}


