#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string B1, B2;
	cin >> B1 >> B2;
	long long b1 = 0, b2 = 0;
	long long tmp = 1;
	for (int i = B1.size() - 1; i >= 0; i--) {
		b1 += tmp * ((int)B1[i] - '0');
		tmp *= 2;
	}
	tmp = 1;
	for (int i = B2.size() - 1; i >= 0; i--) {
		b2 += tmp * ((int)B2[i] - '0');
		tmp *= 2;
	}
	long long ans = b1 * b2;
	string ouput;
	while (ans > 0) {
		if (ans % 2 == 1) ouput.push_back('1');
		else ouput.push_back('0');
		ans /= 2;
	}
	reverse(ouput.begin(), ouput.end());
	cout << ouput << "\n";
}