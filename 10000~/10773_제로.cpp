#include <iostream>
#include <vector>
using namespace std;

int main() {
	int K, data, total;
	cin >> K;
	total = 0;
	vector<int> vec;
	for (int i = 0; i < K; i++) {
		cin >> data;
		if (data == 0) {
			total -= vec.back();
			vec.pop_back();
		}
		else {
			total += data;
			vec.push_back(data);
		}
	}
	cout << total;
}