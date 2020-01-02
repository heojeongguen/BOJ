#include <iostream>
#include <vector>
using namespace std;
vector<int> vec;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, data;
	cin >> n;
	for (size_t i = 0; i < n; i++){
		cin >> data;
		vec.push_back(data);
	}
	unsigned long long ans = 0;
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec.size(); j++) {
			if (i != j) ans += abs(vec[i] - vec[j]);
		}
	}
	cout << ans << endl;
}