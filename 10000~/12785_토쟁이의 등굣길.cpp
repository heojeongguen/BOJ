#include <iostream>
#define endl '\n'
long long DIV = 1000007;
using namespace std;
int X, Y, x, y;
int dp[404][204];

int combi(int n, int r) {
	if (dp[n][r] != 0) return dp[n][r];
	if (r == 0 || n == r) return 1;
	dp[n][r] = (combi(n - 1, r - 1) + combi(n - 1, r)) % DIV;
	return dp[n][r] % DIV;;
}
int main() {
	cin >> X >> Y >> x >> y;
	long long XX = X - x;
	long long YY = Y - y;
	long long xx = x - 1;
	long long yy = y - 1;
	long long to_bread = combi(xx + yy, xx);
	long long to_school = combi(YY + XX, XX);
	cout << (to_bread * to_school) % DIV << endl;
}