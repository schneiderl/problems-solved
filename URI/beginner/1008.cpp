#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main() {
int a,b; 
float s;   
cin>>a>>b>>s;
float v = b*s;
cout << "NUMBER = "<<a<<endl<<"SALARY = U$ "<<fixed<<setprecision(2)<<v<<endl; 
return 0;
}