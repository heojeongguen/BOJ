#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> ans;
int main() {
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i <= K; i++) {
		if (N - i <= 0 || M - (K - i) <= 0) continue;
		ans.push_back(min( (N-i) / 2 , M - (K -i)));
	}
	cout << *max_element(ans.begin(), ans.end()) << "\n";
}