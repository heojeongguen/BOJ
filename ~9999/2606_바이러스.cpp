#include  <iostream>
#include <vector>
using namespace std;

vector<int> vec[101];
bool dp[101];
int ans = 0;

void DFS(int now, int from) {
	if (dp[now] == true) return;

	if (now != 1) ans++;

	dp[now] = true;

	for (int i = 0; i < vec[now].size(); i++) {
		if (now == from || dp[vec[now].at(i)] == true) continue;
		DFS(vec[now].at(i), now);
	}
}

int main() {
	int com, link, data1, data2;
	cin >> com;
	cin >> link;
	for (int i = 1; i <= link; i++) {
		cin >> data1 >> data2;
		vec[data1].push_back(data2);
		vec[data2].push_back(data1);
	}
	DFS(1, -1);
	cout << ans << endl;
}