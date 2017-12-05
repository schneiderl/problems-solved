#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;	
int main(int argc, char const *argv[])
{
	int sum = 0;
	for (int i = 0; i < 16; ++i){ //because there are 16 rows
		int lowest = 5000000000;
		int largest = 0;
		int curr = 0;
		int line[16];
		for (int j = 0; j < 16; ++j){
			cin>>line[j];	
		}
		cout<<line<<endl;
		for (int j = 0; j < 16; ++j){
			for (int k = 0; k < 16; ++k){
				if(k!=j){
					if(line[j]%line[k]==0){
						sum = sum + line[j]/line[k];
					}
				}
			}
		}
	
}
cout<<sum<<endl;
return 0;
}