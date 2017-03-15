#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main() {
double a,b; 
double s;
string n;    
cin>>n>>a>>b;
s = a + ((b/100)*15);
cout << "TOTAL = R$ "<<fixed<<setprecision(2)<<s<<endl; 
return 0;
}