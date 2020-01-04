#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define endl '\n'
typedef long long ll;

vector<int> vec;

int pos[10001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int d; cin >> d;
		vec.push_back(d);
	}
	int pos1, pos2 = -1, pos3;
	for (int i = 0; i < N; i++) {
		if (i == N - 1) break;
		if (vec[i] < vec[i + 1]) {
			pos1 = i;
			pos2 = i+1;
		}
	}

	if (pos2 == -1) {
		cout << -1 << endl;
		return 0;
	}

	int max = -1;
	for (int i = pos2; i < N; i++) {
		if (vec[pos1] < vec[i]) {
			pos3 = i;
		}
	}

	swap(vec[pos1], vec[pos3]);

	sort(vec.begin() + pos2, vec.end());

	for (int i = 0; i < N; i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
}