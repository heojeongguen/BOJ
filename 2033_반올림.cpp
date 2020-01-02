#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
// 99999999
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	int cmp = 1;
	cin >> N;
	while (N > pow(10, cmp)) {
		string str = to_string(N);
		int check = (int)str[str.size() - cmp] - 48;
		if (check >= 5) {
			N /= pow(10, cmp);
			N *= pow(10, cmp);
			N += pow(10, cmp);
		}
		else {
			N /= pow(10, cmp);
			N *= pow(10, cmp);
		}
		cmp++;
	}
	cout << N << endl;
}