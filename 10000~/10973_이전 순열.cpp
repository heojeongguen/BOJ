#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define endl '\n'
typedef long long ll;

vector<int> vec;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int d; cin >> d;
		vec.push_back(d);
	}
	int pos1, pos2 = -1;
	for (int i = N-1; i >= 0; i--) {
		if (i == 0) break;
		if (vec[i-1] > vec[i]) {
			pos1 = i-1;
			pos2 = i;
			break;
		}
	}
	if (pos2 == -1) {
		cout << -1 << endl;
		return 0;
	}
	int max = -1;
	for (int i = N-1; i >= pos2; i--) {
		if (vec[pos1] > vec[i]) {
			swap(vec[pos1], vec[i]);
			sort(vec.begin() + pos2, vec.end(), greater<int>());
			break;
		}
	}
	
	for (int i = 0; i < N; i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
}