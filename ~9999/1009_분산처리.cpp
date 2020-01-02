#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'

long long pow(int a, int b) {
	int ret = 1;
	while (b > 0) {
		if (b % 2 == 1) {
			ret = (ret * a) % 10;
		}
		b /= 2;
		a = (a * a) % 10;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int a, b; cin >> a >> b;
		int ret = pow(a, b);
		if (ret == 0) cout << 10 << endl;
		else cout << ret << endl;
	}
}