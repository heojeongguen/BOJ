#include <iostream>

using namespace std;
unsigned long long W, E;

unsigned long long dp[31][31];

unsigned long long fuc(int w, int e) {


	if (w == W) {
		return (E - e + 1);
	}

	int count = (E - e + 1) - (W - w + 1);

	int next = 0;

	dp[w] = 1;

	while (count--) {
		next++;
		dp[w] += fuc(w + 1, e + next);
	}
	
	return dp[w];
}

int main() {
	int T;

	cin >> T;
	while (T--) {
		fill(dp, dp + 31, 0);
		cin >> W >> E;
		cout << fuc(1, 1) << endl;
	}

}