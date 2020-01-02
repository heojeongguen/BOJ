#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, X, data;
	vector<int> vec;
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		cin >> data;
		vec.push_back(data);
	}
	for (const auto &x : vec) {
		if (x < X) {
			cout << x << " ";
		}
	}
}