#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int data1, data2, ans, in, out;
	int total = 0;
	ans = 0;
	for (int i = 0; i < 4; i++) {
		cin >> out >> in;
		total += (in - out);
		ans = max(ans, total);
	}
	cout << ans << endl;
}