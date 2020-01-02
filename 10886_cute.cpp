#include <iostream>

using namespace std;

int main() {
	int N,D;
	int cnt = 0;
	cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		cin >> D;
		cnt += D;
	}
	if (cnt > N / 2) cout << "Junhee is cute!\n";
	else cout << "Junhee is not cute!\n";
}