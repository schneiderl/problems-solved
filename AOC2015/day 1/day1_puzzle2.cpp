#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

int main(){
	string s; cin>>s;
	int sum = 0; 
	 for (int i = 0; i < s.size(); ++i){
	 	if(s[i]=='('){
	 		++sum;
	 	} else{
	 		--sum; 
	 	}

	 	if(sum==-1){
	 		cout<<i+1<<endl;
	 		return 0; 
	 	}
	 }
	 return 0; 
}

