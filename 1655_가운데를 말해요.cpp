#include <iostream>
#include <deque>
#include <algorithm>
#include <queue>

using namespace std;

deque<int> ans;
priority_queue<int, vector<int>, less<>> mmax;
priority_queue<int, vector<int>, greater<>> mmin;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, D;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> D;
		if (mmin.empty() && mmax.empty()) {
			mmax.push(D);
		}
		else {
			if (mmax.top() <= D) {
				mmin.push(D);
			}
			else {
				mmax.push(D);
			}

			if (mmax.size() < mmin.size()) {
				int tmp = mmin.top();
				mmin.pop();

				mmax.push(tmp);
			}
			else if (mmax.size() > mmin.size() + 1) {
				int tmp = mmax.top();
				mmax.pop();

				mmin.push(tmp);
			}
		}
		ans.push_back(mmax.top());
	}
	for (const auto & x : ans) {
		cout << x << "\n";
	}
}