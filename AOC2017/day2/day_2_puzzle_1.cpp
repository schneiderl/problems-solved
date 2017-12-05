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
		for (int j = 0; j < 16; ++j){
			cin>>curr;
			if(curr>largest){ largest = curr;};
			if(curr<lowest){ lowest = curr;};
		}
	sum = sum + largest - lowest;
}
cout<<sum<<endl;
return 0;
}