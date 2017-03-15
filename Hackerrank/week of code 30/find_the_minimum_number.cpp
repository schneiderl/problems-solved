#include <bits/stdc++.h>

using namespace std;

// I know this code is insane. 
// just figuring out how c++ works
int main(){
    int n;
    cin >> n;
    string s = "";
    for (int i = n; i > 0; --i){
    	if(i!=1){
    		cout << "min(int, ";
    	} else{
    		cout << "int"; 
    		for (int j = 0; j < n-1; ++j){
    		cout << ")";
    		}
            cout<< endl;
    	}
    }
    return 0;
}
