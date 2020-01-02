#include <iostream>
#include <vector>

using namespace std;

pair<int, int> map[300001];
vector<int> ans;
unsigned long long cnt = 0;

void insert(const int &par,const int &data) {
	cnt++;
	if (par < data) {
		if (map[par].second == 0) {
			map[par].second = data;
		}
		else {
			insert(map[par].second, data);
		}
	}

	else if (par > data) {
		if (map[par].first == 0) {
			map[par].first = data;
		}
		else {
			insert(map[par].first, data);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, data;
	int par;
	int root = -1;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> data;
		if (root == -1) {
			root = data;
			ans.push_back(cnt);
		}
		else {
			par = root;
			while (true) {
				cnt++;
				if (par < data) {
					if (map[par].second == 0) {
						map[par].second = data;
						break;
					}
					else {
						par = map[par].second;
						continue;
					}
				}

				else if (par > data) {
					if (map[par].first == 0) {
						map[par].first = data;
						break;
					}
					else {
						par = map[par].first;
						continue;
					}
				}
			}
			ans.push_back(cnt);
		}
	}
	for (const auto &x : ans) {
		cout << x << "\n";
	}
}