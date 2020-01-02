#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, data;
	cin >> N;
	vector<int> vec;
	for (int i = 0; i < N; i++) {
		vec.clear();
		cin >> data;
		int dp[100001] = { 0, };
		for (int j = 2; j <= data; j++) {
			if (dp[j] == 0) {
				vec.push_back(j);
				dp[j] = 1;
			}
			for (int z = 1; z * j < data; z++) {
				dp[j * z] = 1;
			}
		}
		int count;
		for (const auto &x : vec) {
			//cout << "x : " << x << endl;
			count = 0;
			if (data % x == 0) {
				while (data % x == 0) {
					data = data / x;
					count++;
				}
				cout << x << " " << count << endl;
			} 
		}
	}
}