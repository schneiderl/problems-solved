#include <iostream>
#include <string>
using namespace std;

int main() {
   // Complete the program
	string a,b; 
	cin >> a;
	cin >> b;
	cout << a.size() << " " << b.size() << endl; 
	string c = a+b;
	cout << c << endl;
	char aux = a[0];
	a[0] = b[0];
	b[0] = aux;
	cout << a << " " << b << endl;   
    return 0;
}
