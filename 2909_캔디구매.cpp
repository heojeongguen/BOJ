#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int candy, k;
	cin >> candy >> k;
	if (k == 0) cout << (int)candy << endl;
	else if (candy < pow(10, k)) {
		if (candy >= pow(10, k) / 2) {
			cout << (int)pow(10, k);
		}
		else {
			cout << 0 << endl;
		}
	}
	else {
		string str = to_string(candy);
		int size = str.size();
		int check = (int)str[size - k] - 48;
		if (check >= 5) {
			candy /= pow(10, k );
			candy *= pow(10, k);
			candy += pow(10, k);
		}
		else {
			candy /= pow(10, k);
			candy *= pow(10, k);
		}
		cout << (int)candy;
	}
}