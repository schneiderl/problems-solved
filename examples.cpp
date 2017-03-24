
#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

string answer(string s){
	int oB, cB, xAtB = 0;
	oB = s.find("("); cB = s.find(")"); 
	cout<<oB<< " oB "<< xAtB << " xAtB "<< cB<<" cB"<<endl;
	if(oB!=std::string::npos){
	 	string bracket = s.substr(oB+1, cB-oB-1);
	 	cout<<bracket<<endl;
	 	xAtB = bracket.find("X");
		int chars,reps = 0; 
		cout<<chars<<endl;
		// 	bracket.at(xAtB) = ' '; 
	} else{
	// 	return s;
	}
}


int main(){
	string s; cin>>s; 
	string ans = answer(s);
	cout<<ans.size()<<endl; 
}

