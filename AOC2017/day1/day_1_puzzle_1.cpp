#include <bits/stdc++.h>
#include <iostream>
#include <string>


using namespace std;

int main(int argc, char const *argv[])
{
	string s; cin>>s; 
	int sum = 0;
	string curr, prev; curr = ""; prev = "";
	for (int i = 0; i <= s.size(); ++i){
		curr = s[i%s.size()];
		if (curr == prev) {
			if (i==s.size()-1){
				sum = sum + 2*atoi(curr.c_str());
			} else{
				sum = sum + atoi(curr.c_str());
			}
			
		}
		prev = curr; 
	}
	cout<<sum<<endl;
	return 0;
}