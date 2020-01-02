#include <iostream>
#include <vector>
using namespace std;
vector<int> vec;
vector<int> ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N,D,sum = 0;
	int total = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> D;
		total = (i + 1)*D;
		int tmp = total - sum;
		ans.push_back(tmp);
		sum += tmp;
	}
	for (const auto & x : ans) {
		cout << x << " ";
	}
	cout << "\n";
	return 0;
}