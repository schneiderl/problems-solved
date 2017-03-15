#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i){
        long long a; 
        scanf("%lld", &a);
        arr[i] = a;
    }

    for (int i = n-1; i >= 0; --i)
    {
        long long ll = arr[i];

        printf("%lld ", ll );
    }
    return 0;
}
