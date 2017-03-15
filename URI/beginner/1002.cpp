#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main() {
double a;
double b;  
cin >> a;
b = 3.14159 * (a*a); 
cout << "A="<< fixed << setprecision(4)<<b<<endl; 
return 0;
}