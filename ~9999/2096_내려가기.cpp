#include <iostream>
#include <algorithm>
using namespace std;

int mindp[3];
int maxdp[3];
int main() {
	int n;
	int a, b, c;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		if (i == 0) {
			maxdp[0] = a;
			maxdp[1] = b;
			maxdp[2] = c;
			mindp[0] = a;
			mindp[1] = b;
			mindp[2] = c;
		}
		else {
			int max_aa = maxdp[0];
			int max_bb = maxdp[1];
			int max_cc = maxdp[2];
			maxdp[0] = max(max_aa, max_bb) + a;
			maxdp[1] = max({ max_aa, max_bb,max_cc }) + b;
			maxdp[2] = max(max_bb, max_cc) + c;

			int min_aa = mindp[0];
			int min_bb = mindp[1];
			int min_cc = mindp[2];
			mindp[0] = min(min_aa, min_bb) + a;
			mindp[1] = min({ min_aa, min_bb,min_cc }) + b;
			mindp[2] = min(min_bb, min_cc) + c;
		}
	}
	cout << max({ maxdp[0], maxdp[1], maxdp[2] }) << " " <<  min({ mindp[0], mindp[1], mindp[2] }) << endl;
}