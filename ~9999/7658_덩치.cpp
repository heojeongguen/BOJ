#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int>> vec;
vector<pair<int, int>> tmp_vec;
bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}
int main() {
	int N, data1, data2;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> data1 >> data2;
		vec.push_back(make_pair(data1, data2));
	}
	tmp_vec = vec;
	int tmp;
	int ans;
	for (int i = 0; i < vec.size(); i++) {
		ans = 1;
		for (int j = 0; j < vec.size(); j++) {
			if (i == j) continue;
			else {
				if (vec.at(i).first < vec.at(j).first && vec.at(i).second < vec.at(j).second) {
					ans++;
				}
			}
		}
		cout << ans << " ";
	}
}