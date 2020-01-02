#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

vector<int> vec[21];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, K; cin >> N >> K;

	// 이름의 길이에 등수를 push_back
	for (int i = 0; i < N; i++) {
		string input; cin >> input;
		vec[input.size()].push_back(i + 1);
	}

	// i 길이의 이름을 가진 친구들을 등수별로 sort
	for (int i = 0; i < 21; i++) {
		sort(vec[i].begin(), vec[i].end());
	}

	long long ans = 0;
	for (int i = 0; i < 21; i++) {
		// upper_bound를 편의를 위한 push_back
		vec[i].push_back(1e9);
		for (int j = 0; j < vec[i].size()-1; j++) {
			// 자신의 등수보다 K 보다 큰 마지막 친구가 iter로 반환 됩니다.
			auto iter = upper_bound(vec[i].begin(), vec[i].end(), vec[i][j] + K); iter--;
			// 시작 주소를 빼줌으로써 index값을 얻을 수 있고
			auto index = iter - vec[i].begin();
			// 마지막 친구의 index - 현재 index를 해주면 친구의 명수가 나오게 됩니다.
			ans += index - j;
		}
	}
	cout << ans << "\n";
}