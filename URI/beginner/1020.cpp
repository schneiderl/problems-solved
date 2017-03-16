#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main() {
int a;
cin >>a;
int y = a/365; a = a- (y*365);
int m = a/30; a = a - (m*30);
cout<<y<<" ano(s)"<<endl<<m<<" mes(es)"<<endl<<a<<" dia(s)"<<endl; 
return 0;
}