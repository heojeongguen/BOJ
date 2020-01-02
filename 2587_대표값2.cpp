#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector<int> vec;
	int sum = 0;
	int D;
	int loop = 5;
	while (loop--) {
		cin >> D;
		sum += D;
		vec.push_back(D);
	}
	sort(vec.begin(), vec.end());
	cout << sum / 5 << endl;
	cout << vec[vec.size() / 2] << endl;
}