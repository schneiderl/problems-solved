#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main() {
float a,b; cin>>a>>b; 
float s = a/b; 
cout << fixed << setprecision(2)<<s<<endl; 
return 0;
}