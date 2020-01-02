#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	string A, B, tmp, ans;
	cin >> A >> B;
	bool up = false;
	int a, b;
	unsigned long long al = A.size();
	unsigned long long bl = B.size();
	unsigned long long size = max(al, bl);
	unsigned long long gap = abs(al - bl);
	for (int i = 0; i < gap; i++) {
		tmp += "0";
	}
	if (al > bl) {
		B = tmp + B;
	}
	else if(al < bl){
		A = tmp + A;
	}
	int temp;
	for (int i = size-1; i >= 0; i--) {
		a = (int)A.at(i) - 48;
		b = (int)B.at(i) - 48;
		temp = a + b;
		if (up) {
			temp++;
		}

		if (temp >= 10) {
			up = true;
		}
		else {
			up = false;
		}
		ans += to_string(temp % 10);
	}
	if (up) {
		ans += '1';
	}
	reverse(ans.begin(), ans.end());
	for (const auto &x : ans) {
		cout << x;
	}
	cout << endl;
}