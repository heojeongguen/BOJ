#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
set<int> s;
set<int>::iterator iter;
int arr[300002];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, D;
	unsigned long long ans = 0;
	cin >> N;
	s.insert(300001);
	s.insert(0);

	for (int i = 0; i < N; i++) {
		cin >> D;
		s.insert(D);
		
		if (i != 0) {
			iter = s.find(D);
			iter++;
			int right = arr[*iter];
			iter--;
			iter--;
			int left = arr[*iter];
			iter++;
			arr[*iter] = max(right, left) + 1;
			ans += arr[*iter];
		}
		cout << ans << "\n";
	}
}