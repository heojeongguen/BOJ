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

	// �̸��� ���̿� ����� push_back
	for (int i = 0; i < N; i++) {
		string input; cin >> input;
		vec[input.size()].push_back(i + 1);
	}

	// i ������ �̸��� ���� ģ������ ������� sort
	for (int i = 0; i < 21; i++) {
		sort(vec[i].begin(), vec[i].end());
	}

	long long ans = 0;
	for (int i = 0; i < 21; i++) {
		// upper_bound�� ���Ǹ� ���� push_back
		vec[i].push_back(1e9);
		for (int j = 0; j < vec[i].size()-1; j++) {
			// �ڽ��� ������� K ���� ū ������ ģ���� iter�� ��ȯ �˴ϴ�.
			auto iter = upper_bound(vec[i].begin(), vec[i].end(), vec[i][j] + K); iter--;
			// ���� �ּҸ� �������ν� index���� ���� �� �ְ�
			auto index = iter - vec[i].begin();
			// ������ ģ���� index - ���� index�� ���ָ� ģ���� ����� ������ �˴ϴ�.
			ans += index - j;
		}
	}
	cout << ans << "\n";
}