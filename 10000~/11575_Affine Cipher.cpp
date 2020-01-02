#include <iostream>
#include <string>
using namespace std;
#define E(a,b,x) ((a*x+b)%26)



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	string input;
	cin >> N;
	while (N--) {
		int a, b;
		cin >> a >> b;
		cin >> input;
		for (int i = 0; i < input.size(); i++) {
			cout << char(E(a,b,input[i] -'0') + 65);
		}
		cout << "\n";
	}
}