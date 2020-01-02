#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
priority_queue<int, vector<int>, less<> > pq;
int main() {
	int N, M, K, input;
	cin >> N >> M >> K;
	int need = M * K;
	for (int i = 0; i < N; i++) {
		cin >> input;
		pq.push(input);
	}
	int ans = 0;
	int total = 0;
	while (!pq.empty() && total < need) {
		total += pq.top(); pq.pop();
		ans++;
	}
	
	if (total < need) cout << "STRESS\n";
	else cout << ans << "\n";
}