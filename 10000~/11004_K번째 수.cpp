#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, K;
	cin >> N >> K;
	int data;
	vector <int> vec;
	for (int i = 0; i < N; i++) {
		cin >> data;
		vec.push_back(data);
	}
	sort(vec.begin(), vec.end());
	cout << vec.at(K - 1) << endl;
}