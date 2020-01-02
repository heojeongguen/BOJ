#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> file;
vector<pair<int, int>> origin;
vector<pair<int, int>> vec;

bool compareByFile(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

bool compareByMeet(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}
int mini[100001];
int main() {
	int T, N, data1, data2,ans;
	cin >> T;
	while (T--) {
		vec.clear();
		cin >> N;
		ans = N;
		for (int i = 0; i < N; i++) {
			cin >> data1 >> data2;
			vec.push_back(make_pair(data1, data2));
		}
		sort(vec.begin(), vec.end(), compareByFile);
		int tmp = -1;
		for (int i = 0; i < vec.size(); i++) {
			if (tmp == -1) {
				tmp = vec.at(i).second;
			}
			else {
				tmp = min(tmp, vec.at(i).second);
			}
			mini[i] = tmp;
		}
		for (int i = 1; i < vec.size(); i++) {
				if (vec.at(i).second > mini[i - 1]) {
					ans--;
			}
		}
		cout << ans << endl;
	}
}