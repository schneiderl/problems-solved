#include <bits/stdc++.h>
#include <iostream>
#include <string>


using namespace std;

int main(int argc, char const *argv[]){
	string s; cin>>s;
	int cut = s.size()/2;
	int sum = 0;
	string curr = ""; string a = "";
	for (int i = 0; i < s.size(); ++i){
		curr = s[i];
		a = s[(i+cut)%s.size()];
		if(curr==a){
			sum = sum+atoi(curr.c_str());
		}
	}
	cout<<sum<<endl;
}