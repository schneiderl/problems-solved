#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int q;
    cin >> n >> q;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
     cin >> a[a_i];
 }
 for(int a0 = 0; a0 < q; a0++){
    int left;
    int right;
    int x;
    int y;
    cin >> left >> right >> x >> y;
    int s = 0; 
    for (int i = left; i <= right; ++i){
        if(a[i]%x == y){
            s++;
        }           
    }
    cout << s<<endl;
}
return 0;
}
