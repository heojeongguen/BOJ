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

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int ans = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			char c; cin >> c;
			if ((i + j) % 2 == 0) {
				if (c == 'F') ans++;
			}
		}
	}
	cout << ans << endl;
}