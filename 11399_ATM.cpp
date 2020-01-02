#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;
vector<int> vec;
int main() {
	int N,data;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> data;
		vec.push_back(data);
	}

	sort(vec.begin(), vec.end());

	int ans = 0;
	int wait = 0;
	for (const auto&x : vec) {
		wait += x;
		ans += wait;
	}
	cout << ans << endl;
}