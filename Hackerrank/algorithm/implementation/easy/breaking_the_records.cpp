#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> score(n);
	int l,b;
	int cl,cb; cl=0; cb=0;
	for(int score_i = 0; score_i < n; score_i++){
		int cv;
		cin >> cv;
		if(score_i==0){
			l = cv; b=cv;
		} else{
			if(l<cv){
				l=cv; cb++;
			}
			if(b>cv){
				b=cv; cl++;
			}
		}

	}
	cout<<cb<<" "<<cl<<endl; 
	return 0;
}

