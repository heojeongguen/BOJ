#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

vector<unsigned long long> vec;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	unsigned long long D;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> D;
		vec.push_back(D);
	}
	sort(vec.begin(), vec.end());
	int cur_cnt;
	int prev_cnt;
	unsigned long long ans;

	for (int i = 0; i < vec.size(); i++) {
		if (i == 0) {
			cur_cnt = 1;
			ans = vec.at(0);
			prev_cnt = 0;
		}
		else if (i == vec.size() - 1) {
			if (vec.at(i - 1) == vec.at(i)) {
				cur_cnt++;
				if (prev_cnt < cur_cnt) {
					ans = vec.at(i);
				}
			}
			else {
				if (prev_cnt < cur_cnt) {
					ans = vec.at(i);
				}
			}
		}
		else {
			if (vec.at(i - 1) == vec.at(i)) {
				cur_cnt++;
			}
			else {
				if (cur_cnt > prev_cnt) {
					prev_cnt = cur_cnt;
					ans = vec.at(i - 1);
				}
				cur_cnt = 1;
			}
		}
	}
	cout << ans << endl;
}
