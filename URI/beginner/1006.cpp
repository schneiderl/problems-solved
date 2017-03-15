#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main() {
double a;
double b; 
double c;  
cin >> a;
cin >> b;
cin >> c;
float s;
s = ( ((2*a)+(3*b)+(c*5))/10) ; 
cout << "MEDIA = "<< fixed << setprecision(1)<<s<<endl; 
return 0;
}