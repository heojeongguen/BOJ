#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

#define endl '\n'
typedef long long ll;
vector<int> sosu;
bool check[4000001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N; cin >> N; 
	for (int i = 2; i <= N; i++) {
		if (!check[i]) {
			sosu.push_back(i);
			for (int j = 1; j * i <= N; j++) {
				check[i * j] = true;
			}
		}
	}
	int ans = 0;
	if (sosu.size() > 0) {
		int l = 0, r = 0, sum = sosu[0];
		while (l <= r && r < sosu.size()) {
			if (sum < N) {
				sum += sosu[++r];
			}
			if (sum >= N) {
				if (sum == N)
					ans++;
				sum -= sosu[l++];
			}
		}
	}
	cout << ans << endl;
}