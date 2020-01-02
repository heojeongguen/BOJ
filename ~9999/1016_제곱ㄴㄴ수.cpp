#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector<unsigned long long> vec;
vector<unsigned long long> sosu;
bool dp[1000001];
bool flag[1000001];
vector<unsigned long long> test;
int main() {
	unsigned long long MIN, MAX;
	cin >> MIN >> MAX;
	unsigned long long index = sqrt(MAX);
	for (unsigned long long i = 2; i <= index + 1; i++) {
		if (dp[i] == false) {
			sosu.push_back(i * i);
			for (int j = 1; j * i <= index; j++) {
				dp[j * i] = true;
			}
		}
	}
	int ans = 0;
	bool find = false;
	int count = 0;
	for (const auto &x : sosu) {
		unsigned long long start = 1;
		if (MIN > x) {
			if ((MIN - x) % x == 0) {
				start += ((MIN - x) / x);
			}
			else {
				start += ((MIN - x) / x) + 1;
			}
		}
		else {
			start = 1;
		}

		for (unsigned long long i = start; i * x <= MAX; i++) {
			if (flag[x*i % 1000001] == false) {
				flag[(x*i) % 1000001] = true;
				count++;
			}
		}
	}
	cout << MAX - MIN + 1 - count << endl;
}