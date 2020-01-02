#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace  std;
vector<int> vec;
string A, B;
int dup(int start) {
	int ret = 0;
	int j = start;
	for (int i = 0; i < A.size(); i++) {
		if (A.at(i) != B.at(j)) {
			ret++;
		}
		j++;
	}
	return ret;
}

int main() {
	int N;
	int ans = 10000;
	cin >> A >> B;
	for (int i = 0; i + A.size() <= B.size(); i++) {
		ans = min(ans, dup(i));
	}
	cout << ans << endl;
}