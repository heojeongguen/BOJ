#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

vector<int > A;
vector<int> B;

int main() {
	int N;
	int D;
	int ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> D;
		A.push_back(D);
	}
	for (int i = 0; i < N; i++) {
		cin >> D;
		B.push_back(D);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>());
	for (int i = 0; i < N; i++) {
		ans += A.at(i) * B.at(i);
	}
	cout << ans << endl;
}