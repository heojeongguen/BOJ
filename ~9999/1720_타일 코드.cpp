#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

#define endl '\n'
typedef long long ll;

int N;
ll dp[31];
ll ans[31];
ll fun(int n) {
	if (n == 1) return 1;
	else if (n == 2) return 3;
	else if (n == 0) return 0;
	ll& ret = dp[n];
	if (ret != -1) return ret;
	ret = fun(n - 1) + 2 * fun(n-2);
	return ret;
}

ll getAns(int n) {
	if (n == 1) return 1;
	else if (n == 2) return 3;
	else if (n == 0) return 0;
	
	if (n % 2 == 1) 
		ans[n] = ( (fun((n - 1)/2) ) + fun(n) ) / 2;
	else 
		ans[n] = ( fun(n / 2) + 2 * fun((n - 2) / 2) + fun(n) ) / 2;
	
	getAns(n - 1);
	return ans[n];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	cout << getAns(N) << endl;
}