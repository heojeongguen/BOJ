#include <iostream>
#include <vector>
using namespace  std;
vector<int> vec;
int main() {
	int N;
	int ans = 0;
	int cur;
	cin >> N;
	cur = 1000 - N;
	vec.push_back(500);
	vec.push_back(100);
	vec.push_back(50);
	vec.push_back(10);
	vec.push_back(5);
	vec.push_back(1);
	for (int i = 0; i < vec.size(); i++) {
		ans += cur / vec.at(i);
		cur %= vec.at(i);
	}
	cout << ans << endl;
}