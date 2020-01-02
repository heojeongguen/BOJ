#include <iostream>

using namespace std;

bool dp[1002];
int tree[1002];
int ans;
int main() {
	int T,N, data;
	cin >> T;
	while (T--) {
		ans = 0;
		fill(dp, dp + 1001, false);
		fill(tree, tree + 1001, 0);
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> tree[i];
		}
		for (int i = 1; i <= N; i++) {
			if (dp[i] == true) continue;
			dp[i] = true;
			int next = tree[i];
			while (dp[next] == false) {
				dp[next] = true ;
				next = tree[next];
			}
			ans++;
		}
		cout << ans << endl;
	}
}