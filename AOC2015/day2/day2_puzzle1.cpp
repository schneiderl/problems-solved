#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

int min(int a, int b){ return (a<b)? a:b;};

int main(){
	int l = 0 ;
	int s = 0; 
	int c = 0;
	while(cin>>l){
		c++;
		string t = "";
		int w,h = 0;
		cin>>t>>w>>t>>h;
		int ss = 0;
		if((w>=l) && (w>=h)){
			ss = l*h;
		}
		if((l>=w) && (l>=h)){
			ss= w*h;
		}
		if((h>= l) && ( h>=w)){
			ss = l*w;
		}

		s = s+ (2*l*w + 2*w*h + 2*h*l + ss);
	}
	cout<<s<<endl; 
}

