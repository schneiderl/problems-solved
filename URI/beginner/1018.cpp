#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main() {
int a;
cin >>a;
cout<<a<<endl;
int cd;
cd = a/100; cout<<cd<<" nota(s) de R$ 100,00"<<endl; a = a-cd*100;
cd = a/50; cout<<cd<<" nota(s) de R$ 50,00"<<endl; a = a-cd*50;
cd = a/20; cout<<cd<<" nota(s) de R$ 20,00"<<endl; a = a-cd*20;
cd = a/10; cout<<cd<<" nota(s) de R$ 10,00"<<endl; a = a-cd*10;
cd = a/5; cout<<cd<<" nota(s) de R$ 5,00"<<endl; a = a-cd*5;
cd = a/2; cout<<cd<<" nota(s) de R$ 2,00"<<endl; a = a-cd*2;
cd = a/1; cout<<cd<<" nota(s) de R$ 1,00"<<endl; a = a-cd*1;
return 0;
}