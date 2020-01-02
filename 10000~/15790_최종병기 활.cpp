#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> vec;
int main() {
	int N, M, K, D;
	cin >> N >> M >> K;
	int prev = -1;
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		cin >> D;
		if (prev != -1) {
			vec.push_back(D - prev);
			cnt += D - prev;
		}
		prev = D;
	}
	vec.push_back(N - cnt);
	cout << " x :";
	for (const auto & x : vec) {
		cout << x << " ";
	}
	cout << endl;
	if (vec.size() < K) cout << -1 << "\n";
	else if (K == 1) cout << N << endl;
	else cout << vec[(vec.size()-1) - (K - 1)] << endl;
}