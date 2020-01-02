#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	unsigned long long N;
	unsigned long long data;
	vector<unsigned long long> vec;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> data;
		vec.push_back(data);
	}
	sort(vec.begin(), vec.end());
	for (const auto &x : vec) {
		cout << x << "\n";
	}
}