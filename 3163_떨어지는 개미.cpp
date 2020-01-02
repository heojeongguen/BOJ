#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int>> ant;
deque<pair<int, int>> ori;
bool compare(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}

int main() {
	int T;
	int N, L, K, loc, id;
	int count = 0;
	cin >> T;
	while (T--) {
		count = 0;
		ant.clear();
		ori.clear();
		cin >> N >> L >> K;
		for (int i = 1; i <= N; i++) {
			cin >> loc >> id;
			if (id < 0) {
				ant.push_back(make_pair(id, loc));
			}
			else {
				ant.push_back(make_pair(id, L - loc));
			}
			ori.push_back(make_pair(id, loc));
		}
		sort(ant.begin(), ant.end(), compare);
		int ans;
		int tmp;
		int tmp2;
		int last_id, prev_id;
		while (count != K) {
			count++;
			if (ant.size() >= 2) {
				if (ant.at(ant.size() - 2).second == ant.back().second) {
					tmp = ant.back().first;
					if (tmp < 0) {
						last_id = ori.front().first;
					}
					else {
						last_id = ori.back().first;
					}

					tmp = ant.at(ant.size() - 2).first;
					if (tmp < 0) {
						prev_id = ori.front().first;
					}
					else {
						prev_id = ori.back().first;
					}

					if (prev_id < last_id) {
						pair<int, int> tmp_ant;
						tmp_ant = ant.at(ant.size() - 1);
						ant.at(ant.size() - 1) = ant.at(ant.size() - 2);
						ant.at(ant.size() - 2) = tmp_ant;
					}
				}
			}
			tmp = ant.back().first;
			tmp2 = ant.back().second;
			ant.pop_back();
			if (tmp < 0) {
				ans = ori.front().first;
				ori.pop_front();
			}
			else {
				ans = ori.back().first;
				ori.pop_back();
			}
			//cout << "out : " << ans << endl;
		}
		cout << ans << endl;
	}
}
