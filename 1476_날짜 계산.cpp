#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int E, S, M, e = 1, s = 1, m = 1, Y = 1;
	cin >> E >> S >> M;
	while (E != e || S != s || M != m) {
		e = max((e + 1) % 16,1);
		s = max((s + 1) % 29, 1);
		m = max((m + 1) % 20, 1);
		Y++;
	}
	cout << Y;
	
}