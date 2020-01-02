#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int main() {
	int N, data;
	vector<int> vec;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> data;
		vec.push_back(data);
	}
	sort(vec.begin(), vec.end());
	for (const auto &x : vec) {
		cout << x << endl;
	}
}