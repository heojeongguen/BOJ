#include <iostream>
#include <vector>
using namespace std;
vector<int> ans[3];
int time[3];
int main() {
	int a, b, c, aa, bb, cc;
	for (int i = 0; i < 3; i++) {
		cin >> a >> b >> c >> aa >> bb >> cc;
		int t = a * 3600 + b * 60 + c;
		int tt = aa * 3600 + bb * 60 + cc;
		time[i] = tt - t;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 3600; j >= 1; j /= 60) {
			cout << time[i] / j << " ";
			time[i] %= j;
		}
		cout << endl;
	}
}