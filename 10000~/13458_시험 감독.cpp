#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> vec;
vector<int> vvec;
int dp[1000001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	int B, C, D;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> D;
		vec.push_back(D);
	}
	unsigned long long ans = 0;
	cin >> B >> C;
	for (int i = 0; i < vec.size(); i++) {
		int tmp = vec[i];
		tmp -= B;
		ans++;
		if (tmp > 0){
			if (tmp % C == 0) {
				ans += tmp / C;
			}
			else {
				ans += tmp / C;
				ans++;
			}
		}
	}
	cout << ans << endl;
}