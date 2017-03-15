#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main() {
double r;  
cin >> r;
double v = (4/3.0) * 3.14159 * (r*r*r); 
cout << "VOLUME = "<< fixed << setprecision(3)<<v<<endl; 
return 0;
}