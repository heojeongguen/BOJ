#include <iostream>
#include <set>
using namespace std;
set<int> s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M,D;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> D;
		s.insert(D);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> D;
		if (s.end() == s.find(D)) {
			cout << 0 << " ";
		}
		else {
			cout << 1 << " ";
		}
	}
}