#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	vector<int> vec;
	for (int i = 0; i < 3; i++) {
		int data; cin >> data;
		vec.push_back(data);
	}
	sort(vec.begin(), vec.end());
	for (auto& x : vec) cout << x << " ";
	
}