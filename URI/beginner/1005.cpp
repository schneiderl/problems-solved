#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main() {
double a;
double b;  
cin >> a;
cin >> b;
float s;
s = ( ((3.5*a)+(7.5*b))/11) ; 
cout << "MEDIA = "<< fixed << setprecision(5)<<s<<endl; 
return 0;
}