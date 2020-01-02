#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
vector<int> vec;
int main() {
	vector <int> vec;
	int D;
	for (int i = 0; i < 4; i++) {
		cin >> D;
		vec.push_back(D);
	}
	sort(vec.begin(), vec.end(),greater<int>());
	cout << vec[1] * vec[3] << endl;
}