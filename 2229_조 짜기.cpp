#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;



int main() {
	int N,D ,ans = 0;
	deque<int> deq;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> D;
		deq.push_back(D);
	}
	sort(deq.begin(), deq.end());
	while (!deq.empty()) {
		ans += deq.back() - deq.front(); deq.pop_back(); deq.pop_front();
	}
	cout << ans << endl;
}