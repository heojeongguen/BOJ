#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int N, C;
bool arrive(int data);
bool R[10];
int main() {
		int data;
		cin >> N >> C;
		for (int i = 0; i < 10; i++) {
			R[i] = true;
		}
		for (int i = 0; i < C; i++) {
			cin >> data;
			R[data] = false;
		}
		int result_plus = -1;
		int result_minus = -1;
		int result;
		int c = -1;
		int size;
		int ans;
		result = -1;
		for (int i = 0; i <= 1000000; i++) {
			if (N + i <= 1000000)
				if (arrive(N + i)) {
					result = N + i;
					break;
				}
		}

		size = to_string(result).size();
		int baseGap = abs(100 - N);

		if (result == -1) {
			ans = baseGap;
		}
		else if (result == 0 && N != 0) {
			ans = min(baseGap, abs(result - N) + 1);
		}
		else if (result != 0 && N == 0) {
			ans = (baseGap, abs(result - N) + size);
		}
		else if (result == 0 && N == 0) {
			ans = 1;
		}
		else if (result != 0 && N != 0) {
			if (result == N) {
				ans =  min(baseGap, size);
			}
			else {
				ans = min(baseGap, abs(N - result) + size);
			}

		}
		result = -1;
		for (int i = 0; i <= 1000000; i++) {
			if (N - i >= 0)
				if (arrive(N - i)) {
					result = N - i;
					break;
				}
		}

		size = to_string(result).size();

		if (result == -1) {
			ans = min(ans, baseGap);
		}
		else if (result == 0 && N != 0) {
			ans = min(ans, abs(result - N) + 1);
		}
		else if (result != 0 && N == 0) {
			ans = (ans, abs(result - N) + size);
		}
		else if (result == 0 && N == 0) {
			ans = min(ans,1);
		}
		else if (result != 0 && N != 0) {
			if (result == N) {
				ans = min(ans, size);
			}
			else {
				ans = min(ans, abs(N - result) + size);
			}
		}
		cout <<  ans << endl;
	
	

}
bool arrive(int data) {
	string str = to_string(data);
	for (const auto &x : str) {
		if (!R[((int)x - 48)]) {
			return false;
		}
	}
	return true;
}