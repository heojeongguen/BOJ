#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

int main() {
	int N,D;
	cin >> N;
	vector <int> vec;
	vector <int> vec2;
	for (int i = 0; i < N; i++) {
		cin >> D;
		vec.push_back(D);
	}
	int ans = -1;
	sort(vec.begin(), vec.end(), greater<int>());
	for (int i = 0; i < vec.size(); i++) {
		ans = max(ans, vec.at(i) + i + 1);
	}
	cout << ans + 1 << endl;
}