#include <iostream>
using namespace std;

const unsigned long long NUM = 1001;
const unsigned long long DIV = 10007;
unsigned long long dp[NUM] = { 0 , };

unsigned long long ntile(unsigned long long n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return 1;

	if (dp[n] > 0) { return dp[n] % DIV; }

	dp[n] = (ntile(n - 1) + ntile(n - 2)) % ;

	return dp[n];
}

int main()
{
	unsigned long long num, ans;
	cin >> num;
	ans = ntile(num);
	cout << ans << endl;
}