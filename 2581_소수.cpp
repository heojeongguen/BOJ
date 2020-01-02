#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> vec;
bool dp[10001];

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 2; i <= M; i++) {
		if (!dp[i]) vec.push_back(i);

		for (int j = 1; i * j <= M; j++) {
			dp[i*j] = true;
		}
	}
	int total = 0, mini = 10001;
	for (const auto & x : vec) {
		if (x >= N) {
			mini = min(mini, x);
			total += x;
		}
	}
	if (mini == 10001) {
		cout << -1 << endl;
	}else
	cout << total << endl << mini << endl;
}