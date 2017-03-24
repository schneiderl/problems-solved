#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <unordered_set>
using namespace std;

string IntToString (int a)
{
  ostringstream temp;
  temp<<a;
  return temp.str();
}

int main() {
  string s; 
  cin>>s; 
  int currxS, curryS, curryR, currxR, currx, curry;
  currxS = 0; curryS = 0; curryR = 0; currxR = 0; currx = 0; curry = 0;
  int sum = 0;
  unordered_set<string> pos; 
  string str = IntToString(currx) + IntToString(curry);
  pos.insert(str); sum++;
  for (int i = 0; i < s.size(); ++i){
    if(i%2==0){
      switch(s[i]){
        case '<': currxS = currxS-1; break;
        case '^':curryS = curryS-1; break;
        case '>':currxS = currxS +1; break;
        case 'v':curryS = curryS +1; break;
      }
      currx = currxS; curry = curryS; 
    } else{
      switch(s[i]){
        case '<': currxR = currxR-1;; break;
        case '^':curryR = curryR-1;; break;
        case '>':currxR = currxR +1; break;
        case 'v':curryR = curryR +1; break;
      }
      currx = currxR; curry = curryR;
    }
    string str = IntToString(currx) + IntToString(curry);
    if(pos.find(str)==pos.end()){
      pos.insert(str);
      ++sum;
    }
  }

  cout<<sum<<endl; 
}

