#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;
vector<pair<int, int>> vec;
vector<int> id;
int main() {
	int D;
	for (int i = 1; i <= 8; i++) {
		cin >> D;
		vec.push_back(make_pair(D, i));
	}
	int sum = 0;
	sort(vec.begin(), vec.end(), greater<>());
	for (int i = 0; i < 5; i++) {
		sum += vec[i].first;
	}
	cout << sum << endl;
	for (int i = 0; i < 5; i++) {
		id.push_back(vec[i].second);
	}
	sort(id.begin(), id.end());
	for (const auto & x : id) {
		cout << x << " ";
	}
}