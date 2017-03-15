#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main() {
int c1,c2,p1,p2; 
double v1,v2;
cin>>c1>>p1>>v1>>c2>>p2>>v2;
double s = p1*v1+p2*v2; 
cout << "VALOR A PAGAR: R$ "<<fixed<<setprecision(2)<<s<<endl; 
return 0;
}