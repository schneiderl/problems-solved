#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t; cin>>t; 
    for (int i = 0; i < t; ++i){
    	int a,b,c; cin>>a>>b>>c; 
    	int res = ((b+c)%a-1); 
    	if (res<=0){
			res = a;    		
    	}
    	cout<<res<<endl;
    }
    return 0;
}
