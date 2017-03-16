#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main() {
int a;
cin >>a;
int h = a/3600; a = a- (h*3600);
int m = a/60; a = a - (m*60);
cout<<h<<":"<<m<<":"<<a<<endl; 
return 0;
}