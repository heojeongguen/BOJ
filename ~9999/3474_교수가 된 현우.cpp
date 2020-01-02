#include <iostream>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, t;
	cin >> t;
	while (t--)
	{
		unsigned long long sum = 0;
		cin >> n;
		for (int i = 5; i <= n; i *= 5)
		{
			sum += n / i;
		}
		cout << sum << '\n';
	}
}