#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> pakage;
vector<int> each;
int main() {
	int N, M, data1, data2, ans = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> data1 >> data2;
		pakage.push_back(data1);
		each.push_back(data2);
	}
	for (const auto &x : each) {
		pakage.push_back(6 * x);
	}
	sort(pakage.begin(), pakage.end());
	sort(each.begin(), each.end());
	int byPackage;
	int byEach;
	byPackage = N / 6;
	byEach = N % 6;
	ans += byPackage * pakage.front();
	ans += min(pakage.front(),byEach * each.front());
	cout << ans << endl;
}