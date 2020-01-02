#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, M,data, ans = 0;
	cin >> N >> M;
	deque<int> dq;
	vector<int> vec;
	int c = 0;
	for (int i = 0; i < N; i++) {
		dq.push_back(i + 1);
	}
	for (int i = 0; i < M; i++) {
		cin >> data;
		vec.push_back(data);
	}

	while (c < M) {
		for (unsigned i = 0; i < vec.size(); i++) {
			if (vec.at(i) == dq.front()) {
				dq.pop_front();
				c++;
			}
			else {
				for (unsigned j = 0; j < dq.size(); j++) {
					if (dq.at(j) == vec.at(i)) {
						if (j < dq.size() - j) {
							for (unsigned z = 0; z < j; z++) {
								dq.push_back(dq.front());
								dq.pop_front();
								ans++;
							}
						}
						else {
							for (unsigned z = 0; z < dq.size() - j; z++) {
								dq.push_front(dq.back());
								dq.pop_back();
								ans++;
							}
						}
						break;
					}
				}
				dq.pop_front();
				c++;
			}
		}
	}
	cout << ans;
}