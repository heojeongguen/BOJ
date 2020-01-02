#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
deque <pair<unsigned long long, unsigned long long>> deq;

bool compare(pair<unsigned long long, unsigned long long> a, pair<unsigned long long, unsigned long long> b) {
	if (a.second == b.second) {
		return (a.first < b.first);
	}
	else {
		return a.second < b.second;
	}
}

int main() {
	int T, N;
	cin >> T;
	N = T;

	unsigned long long data1, data2;
	pair<unsigned long long, unsigned long long> tmp;
	while (T--) {
		cin >> data1 >> data2;
		deq.push_back(make_pair(data1, data2));
	}
	sort(deq.begin(), deq.end(), compare);

	//for (const auto &x : deq) {
	//	cout << x.first << " " << x.second << endl;
	//}
	int ans = 0;
	int curE = 0;

	for (int i = 0; i < N; i++) {
		if (deq.at(i).first >= curE) {
			curE = deq.at(i).second;
			ans++;
		}
    }
	cout  << ans << endl;
}
