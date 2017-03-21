#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int q; 
	cin>>q; 
	for (int j = 0; j < q; ++j){
		string s; 
		cin>>s;
		int l = s.size(); 
		int count = 0; 
		if(l%2!=0){
			cout<<"-1"<<endl;
		} else{
			string s1 = s.substr(0, l/2);
			string s2 = s.substr(l/2, l/2);
			for (int i = 0; i < s2.size(); ++i){
				int c = s1.find(s2[i]);
				if(c!=std::string::npos){
					s1[c] = '1';
				} else{
					count++; 
				}
			}
			cout<<count<<endl;
		}
	}
	return 0;
}
