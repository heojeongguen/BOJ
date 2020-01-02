#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int>b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}

int main() {
	int N, x , y;
	pair<int, int> loc;
	vector<pair<int, int>> vec;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		loc = { x , y };
		vec.push_back(loc);
	}
	sort(vec.begin(), vec.end(), compare);
	for (const auto &x : vec) {
		cout << x.first << " " << x.second << "\n";
	}
}