#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main() {
double a,b,c,d; 
cin >> a>>b>>c>>d;
cout << fixed<<setprecision(4)<<sqrt(pow(b-a),2)+pow((d-c),2)<<endl; 
return 0;
}