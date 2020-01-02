#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> vec;


bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}

int main() {
	int N, D1, D2;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> D1 >> D2;
		vec.push_back(make_pair(D1, D2));
	}
	sort(vec.begin(), vec.end(), compare);
	for (const auto & x : vec) {
		cout << x.first << " " << x.second << "\n";
	}
}