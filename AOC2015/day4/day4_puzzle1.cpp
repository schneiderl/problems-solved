#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <unordered_set>
#include "md5.h"
using namespace std;

const string input = "yzbqklnj";

string IntToString (int a)
{
  ostringstream temp;
  temp<<a;
  return temp.str();
}

int main(int argc, char *argv[])
{
  int c = 0; 
  while(true){
    string intToStr = IntToString(c);
    string s = md5(input+intToStr);
    string sub = s.substr(0,5);
    if (sub=="00000"){
      cout<<c<<endl;
      return 0;
    }
    c++;
  }
}

