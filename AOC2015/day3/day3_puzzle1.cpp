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
      int currx, curry = 0; 
      int sum = 0;
      unordered_set<string> pos; 
      string str = IntToString(currx) + IntToString(curry);
      pos.insert(str); sum++;
      for (int i = 0; i < s.size(); ++i){
            switch(s[i]){
                  case '<': --currx; break;
                  case '^':--curry; break;
                  case '>':++currx; break;
                  case 'v':++curry; break;
            }

      string str = IntToString(currx) + IntToString(curry);
      if(pos.find(str)==pos.end()){
            pos.insert(str);
            ++sum;
      }
}

      cout<<sum<<endl; 
}

