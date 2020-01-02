#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> vec;
int main() {
	int s;
	while (true) {
		cin >> s;
		if (s == -1) break;
		vec.clear();
		vec.push_back(s);
		int cnt = 0;
		while (true) {
			cin >> s;
			if (s == 0) break;
			vec.push_back(s);
		}
		sort(vec.begin(), vec.end());
		for (int i = 0; i < vec.size() - 1; i++) {
			int it = lower_bound(vec.begin() + i + 1, vec.end(), vec[i] * 2) - vec.begin();
			if (it >= 0 &&  it < vec.size() && vec[it] == vec[i] * 2) cnt++;
		}
		cout << cnt << endl;
	}
}