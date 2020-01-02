#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
unsigned long long ans = 0;
vector<int> vec;
int arr[10001] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k, data;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> data;
		vec.push_back(data);
	}
	arr[0] = 1;
	for (const auto &x : vec) {
		for (int i = x; i <= k; i++) {
			arr[i] += arr[i - x];
		}
	}
	cout << arr[k] << endl;
}